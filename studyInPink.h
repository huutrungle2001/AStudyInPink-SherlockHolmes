#ifndef studyInPink_h
#define studyInPink_h

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Check if a string can be converted to int
bool isInt(string s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string notebook1(string ntb1) {
    // File stream
    ifstream read(ntb1);

    // Read the first line
    string line;
    getline(read, line);

    // Get string n1
    string temp(line, 11, 14);

    // Check convertable
    if (!isInt(temp) || stoi(temp) <= 0) {
        return "0000000000";
    }

    // Convert to int
    int n1 = stoi(temp);

    // Array to count occurences
    int count[10] = {};

    // Read the second line
    getline(read, line);

    // Put the second line to string stream
    stringstream ss(line);
    int c;

    // Read and count occurences of number in the second line
    for (int i = 0; i < n1; i++) {
        ss >> c;
        count[c]++;
    }

    // Convert array to string
    string occurrences = "";
    for (int i : count) {
        occurrences += to_string(i % 10);
    }

    read.close();
    return occurrences;
}

// Encrypt cntP
string encrypt(int cntP) {
    if (cntP < 10000) {
        cntP *= cntP;
    }

    string cipher = to_string(cntP);

    while (cipher.size() < 10) {
        cipher += '9';
    }

    return cipher;
}

// Count occurence of one string in another string
int countOccurence(string s, string delim) {
    int start = 0;
    int end = s.find(delim);
    int count = 0;
    while (end != -1) {
        count++;
        start = end + delim.length();
        end = s.find(delim, start);
    }

    return count;
}

// Count occurence of "pink" and "Pink" in a string
int countPink(string s) {
    return countOccurence(s, "pink") + countOccurence(s, "Pink");
}

string notebook2(string ntb2) {
    // File stream
    ifstream read(ntb2);

    // Read the first line
    string line;
    getline(read, line);
    int n2 = stoi(line);

    // Verify n2
    if (!isInt(line) || line.size() < 5 || n2 < 5 || n2 > 100) {
        return "1111111111";
    }

    // Count pink
    int cntP = 0;
    for (int i = 0; i < n2; i++) {
        getline(read, line);
        cntP += countPink(line);
    }

    read.close();
    return encrypt(cntP);
}

#define N 10

// Split a string of numbers into an array of numbers
int* split(string& str, string delimiter) {
    // Allocate memory for the array
    int* row = new int[N];

    int start = 0;
    int end = str.find(delimiter);
    int i = 0;

    // Parse number one by one
    while (end != -1) {
        row[i] = abs(stoi(str.substr(start, end - start)));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
        i++;
    }
    row[i] = abs(stoi(str.substr(start, end - start)));

    return row;
}

// Display a matrix
void showMatrix(int** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Read matrix from file
int** getMatrix(string ntb3) {
    ifstream read(ntb3);

    // Allocate memory for the matrix
    int** matrix = new int*[N];
    string line;
    int i = 0;
    // Read a string of numbers and turn it to an array of numbers
    while (getline(read, line)) {
        matrix[i] = split(line, "|");
        i++;
    }

    read.close();
    return matrix;
}

// Check if a number is prime number
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Get the smallest prime number bigger than n
int nextPrime(int n) {
    if (n < 2) {
        return 2;
    }

    while (!isPrime(n)) {
        n++;
    }

    return n;
}

// Turn all number above the main diagonal into prime numbers
void primeAbove(int** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            matrix[i][j] = nextPrime(matrix[i][j]);
        }
    }
}

// Fibonacci array
int Fib[100] = {0};

// Get the nth Fibonacci number
int getFib(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return (Fib[n] = 1);
    }

    if (Fib[n]) {
        return Fib[n];
    }

    // If n is odd then k = (n + 1)/2
    // F(n) = F(k)*F(k) + F(k-1)*F(k-1)
    if (n & 1) {
        int k = (n + 1) / 2;
        Fib[n] = getFib(k) * getFib(k) + getFib(k - 1) * getFib(k - 1);
    }

    // If n is even then k = n/2:
    // F(n) = (2*F(k-1) + F(k))*F(k)
    else {
        int k = n / 2;
        Fib[n] = (2 * getFib(k - 1) + getFib(k)) * getFib(k);
    }

    return Fib[n];
}

// Get the smallest Fibonacci number biggther than n
int nextFib(int n) {
    int i = 0;
    while (getFib(i) < n) {
        i++;
    }
    return getFib(i);
}

// Turn all number below the main diagonal into Fibonacci number
void FiboBelow(int** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            matrix[i][j] = nextFib(matrix[i][j]);
        }
    }
}

// Sort an array from index start to index end
void sortRange(int* arr, int start, int end) {
    for (int i = start; i <= end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Sort three las columns of the matrix
void sort3LastMatrixCols(int** matrix) {
    for (int i = 0; i < N; i++) {
        sortRange(matrix[i], 7, 9);
    }
}

// Get the index of the largest element on a row
int maxOnRow(int* row) {
    int maxIndex = 0;

    for (int i = 1; i < N; i++) {
        if (row[i] >= row[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

// Get the code from the matrix
string getCode(int** matrix) {
    string cipher = "";

    for (int i = 0; i < N; i++) {
        cipher += to_string(maxOnRow(matrix[i]));
    }

    return cipher;
}

string notebook3(string ntb3) {
    // Read matrix from file
    int** matrix = getMatrix(ntb3);
    // Turn all number above the main diagonal into prime numbers
    primeAbove(matrix);
    // Turn all number below the main diagonal into Fibonacci number
    FiboBelow(matrix);
    // Sort three las columns of the matrix
    sort3LastMatrixCols(matrix);

    // Get the code from the matrix
    return getCode(matrix);
}

// Convert char to int
int ctoi(char c) {
    return c - '0';
}

// Generate password by adding two password
string genPass(string password1, string password2) {
    string password = "";
    int carry = 0;

    for (int i = 0; i < N; i++) {
        int sum = ctoi(password1[i]) + ctoi(password2[i]) + carry;
        password += to_string(sum % 10);
        carry = sum / 10;
    }

    return password;
}

// Generate List Passwords
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    string password = pwd1 + "," + pwd2 + "," + pwd3 + ",";
    password += (genPass(pwd1, pwd2) + "," + genPass(pwd1, pwd3) + "," + genPass(pwd2, pwd3)) + ",";
    password += (genPass(genPass(pwd1, pwd2), pwd3) + "," + genPass(pwd1, genPass(pwd2, pwd3))) + ",";
    password += (genPass(genPass(pwd1, pwd2), genPass(pwd1, pwd3)));

    return password;
}

bool chaseTaxi(int arr[100][100], string points, string moves, string& outTimes, string& outCatchUps) {
    return false;
}

string enterLaptop(string tag, string message) {
    ifstream read(tag);
    string line = "";

    // Read the first line
    getline(read, line);

    // Get email
    int start = line.find(" ") + 1;
    string email = line.substr(start, line.back());

    // Read the second line
    getline(read, line);

    // Get the number
    start = line.find(" ") + 1;
    int end = line.find(" ", start + 1);
    int n3 = stoi(line.substr(start, end));

    // Generate password
    string password = email + ";";
    for (int i = 0; i < n3; i++) {
        password += message;
    }

    read.close();
    return password;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */

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

string notebook3(string ntb3) {
    // Complete this function to gain point
    return "000000000";
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    return "000000000";
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string& outTimes,
    string& outCatchUps) {
    // Complete this function to gain point
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    return "";
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */

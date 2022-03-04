/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2022
 * Author: Vu Van Tien
 * Date: 10.02.2022
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

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
    if (!isInt(temp)) {
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

string notebook2(string ntb2) {
    // Complete this function to gain point
    return "000000000";
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

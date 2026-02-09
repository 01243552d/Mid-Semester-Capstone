#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string indexNumber;
    string name;

    Student() {}

    Student(string idx, string n) {
        indexNumber = idx;
        name = n;
    }

    void display() const {
        cout << indexNumber << " - " << name << endl;
    }
};

#endif

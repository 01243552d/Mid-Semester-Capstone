#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

vector<Student> students;

void registerStudent() {
    string idx, name;

    cout << "Enter Index Number: ";
    cin >> idx;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    students.push_back(Student(idx, name));
    cout << "Student registered successfully!\n";
}

void viewStudents() {
    cout << "\n--- REGISTERED STUDENTS ---\n";
    if (students.empty()) {
        cout << "No students registered.\n";
        return;
    }

    for (const auto& s : students) {
        s.display();
    }
}

int main() {
    int choice;

    do {
        cout << "\nDIGITAL ATTENDANCE SYSTEM\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}


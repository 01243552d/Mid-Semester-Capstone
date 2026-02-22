#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

// ------------------ Student Structure ------------------
struct Student {
    string indexNumber;
    string fullName;
    string attendance;   // Stores Present / Late / Absent / Not Marked
};

// Temporary storage (RAM only)
vector<Student> students;

// ------------------ Check Duplicate Index ------------------
bool indexExists(const string& indexNumber) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == indexNumber) {
            return true;
        }
    }
    return false;
}
// ------------------ Validate Index Number ------------------
bool isValidIndex(const string& indexNumber) {
    // Must be 9 characters: first 8 digits, last 1 letter (lowercase or uppercase)
    if (indexNumber.length() != 9) return false;

    // Check first 8 characters are digits
    for (int i = 0; i < 8; i++) {
        if (!isdigit(indexNumber[i])) return false;
    }

    // Check last character is a letter
    if (!isalpha(indexNumber[8])) return false;

    return true;
}

// ------------------ Register Student ------------------
void registerStudent() {
    string indexNumber, fullName, answer;

    while (true) {
        cout << "\nEnter Index Number: ";
        cin >> indexNumber;

        // Check format first
        if (!isValidIndex(indexNumber)) {
            cout << "Error: Invalid index number format! Must be 8 digits followed by a letter.\n";
            continue; // retry
        }

        // Check duplicates
        if (indexExists(indexNumber)) {
            cout << "Error: Index number already exists!\n";
            continue; // retry
        }

        cout << "You entered " << indexNumber << ". Confirm? (Y/N): ";
        cin >> answer;

        // Convert to lowercase
        for (size_t i = 0; i < answer.size(); i++)
            answer[i] = tolower(answer[i]);

        if (answer == "y" || answer == "yes") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input
            cout << "Enter Full Name: ";
            getline(cin, fullName);

            Student s;
            s.indexNumber = indexNumber;
            s.fullName = fullName;
            s.attendance = "Not Marked";
            students.push_back(s);

            cout << "Student Registered Successfully!\n";
            return;
        }
        else if (answer == "n" || answer == "no") {
            cout << "Try entering index number again.\n";
        }
        else {
            cout << "Invalid input. Enter Y or N.\n";
        }
    }
}
// ------------------ View Students ------------------
void viewStudents() {
    cout << "\n--- Students ---\n";

    if (students.empty()) {
        cout << "No students registered yet.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1
             << ". Index: " << students[i].indexNumber
             << " | Name: " << students[i].fullName
             << " | Attendance: " << students[i].attendance
             << endl;
    }
}

// ------------------ Main ------------------
int main() {
    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register student\n";
        cout << "2. View students\n";
        cout << "3. Search student\n";
        cout << "4. View Lecture Session\n";
        cout << "5. Mark Attendance\n";
        cout << "6. Update Attendance\n";
        cout << "0. Exit\n";
        cout << "Choice:-> ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        switch(choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                ViewLectureSession();
                break;
            case 5:
                MarkAttendance();
                break;
            case 6:
                UpdateAttendance();
                break;  
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}

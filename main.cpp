#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    Student s1("EE123", "Kelvin Sam");

    cout << "Student Details:\n";
    s1.display();

    return 0;
}

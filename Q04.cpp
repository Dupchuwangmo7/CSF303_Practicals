#include <iostream>
using namespace std;

int main() {
    string name;
    int studentNo;
    int age;
    int currentYear = 2026;   

    cout << "Enter your name        : ";
    getline(cin, name);

    cout << "Enter student number   : ";
    cin >> studentNo;

    cout << "Enter your age         : ";
    cin >> age;

    int birthYear = currentYear - age;
    int yearAt100 = birthYear + 100;

    cout << "\n----------------------------------------\n";
    cout << "Summary\n";
    cout << "----------------------------------------\n";
    cout << "Name           : " << name << endl;
    cout << "Student No     : 0" << studentNo << endl;
    cout << "Year of Birth  : " << birthYear << endl;
    cout << "Year at Age 100: " << yearAt100 << endl;

    return 0;
}
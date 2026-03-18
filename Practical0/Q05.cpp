#include <iostream>
using namespace std;

int main() {
    string name = "Dupchu Wangmo";
    int studentNo = 2230282;
    int mark;

    cout << "Enter mark: ";
    cin >> mark;

    if(mark < 0 || mark > 100) {
        cout << "Error: Invalid mark!\n";
        return 0;
    }

    string grade;

    if(mark >= 75)
        grade = "Distinction";
    else if(mark >= 60)
        grade = "Merit";
    else if(mark >= 40)
        grade = "Pass";
    else
        grade = "Fail";

    cout << "----------------------------------------\n";
    cout << "Student : " << name << " (" << studentNo << ")\n";
    cout << "Mark    : " << mark << endl;
    cout << "Grade   : " << grade << endl;

    if(mark >= 40)
        cout << "Result  : Congratulations, you passed!\n";
    else
        cout << "Result  : Sorry, you failed.\n";

    cout << "----------------------------------------\n";

    return 0;
}
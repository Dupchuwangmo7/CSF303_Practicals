#include <iostream>
using namespace std;

int main() {
    string firstName = "Dupchu";
    string fullName = "Dupchu Wangmo";
    int studentNo = 2230282;

    // Repeat name
    for(int i = 0; i < firstName.length(); i++)
        cout << firstName << endl;

    cout << "\nTriangle:\n";
    for(int i = 1; i <= fullName.length(); i++) {
        for(int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    int lastDigit = studentNo % 10;

    cout << "\nTimes Table for " << lastDigit << endl;
    for(int i = 1; i <= 10; i++)
        cout << lastDigit << " x " << i << " = " << lastDigit*i << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int studentNo = 2230282; 

    int temp = studentNo;
    int sum = 0;

    
    while(temp > 0) {
        sum += temp % 10;   
        temp /= 10;         
    }

    cout << "Student Number  : 0" << studentNo << endl; 
    cout << "Digit Sum       : " << sum << endl;

    
    if(studentNo % 2 == 0)
        cout << "Odd / Even      : Even\n";
    else
        cout << "Odd / Even      : Odd\n";

    cout << "Remainder (%7)  : " << studentNo % 7 << endl;
    cout << "Multiplied by 3 : " << studentNo * 3 << endl;

    return 0;
}
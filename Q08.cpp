#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate digit sum
int digitSum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check prime number
bool isPrime(int n) {
    if(n <= 1)
        return false;

    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

// Function to count vowels
int countVowels(string s) {
    int count = 0;

    for(char c : s) {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            count++;
    }

    return count;
}

// Function to reverse string
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {

    string name = "Dupchu Wangmo";
    int studentNo = 2230282;

    cout << "========================================\n";
    cout << "  Function Results for " << name << endl;
    cout << "  Student No: 0" << studentNo << endl;
    cout << "========================================\n";

    cout << "digitSum(" << studentNo << ") : " << digitSum(studentNo) << endl;

    cout << "isPrime(" << studentNo << ")  : ";
    if(isPrime(studentNo))
        cout << "Yes\n";
    else
        cout << "No\n";

    cout << "countVowels(" << name << ") : " << countVowels(name) << endl;

    cout << "reverseString(" << name << "): "
         << reverseString(name) << endl;

    cout << "========================================\n";

    return 0;
}
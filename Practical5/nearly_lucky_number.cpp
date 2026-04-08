#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    int count = 0;

    // Count lucky digits
    for (char c : n) {
        if (c == '4' || c == '7') {
            count++;
        }
    }

    // Check if count is lucky
    string cnt = to_string(count);
    bool isLucky = true;

    for (char c : cnt) {
        if (c != '4' && c != '7') {
            isLucky = false;
            break;
        }
    }

    if (isLucky && count > 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
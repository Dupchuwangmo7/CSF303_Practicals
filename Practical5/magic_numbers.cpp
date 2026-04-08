#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ) {
        // Check "144"
        if (i + 2 < s.length() && s.substr(i, 3) == "144") {
            i += 3;
        }
        // Check "14"
        else if (i + 1 < s.length() && s.substr(i, 2) == "14") {
            i += 2;
        }
        // Check "1"
        else if (s[i] == '1') {
            i += 1;
        }
        // Invalid case
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
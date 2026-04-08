#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> uniqueChars;

    // Store unique characters
    for (char c : s) {
        uniqueChars.insert(c);
    }

    // Check even or odd
    if (uniqueChars.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}
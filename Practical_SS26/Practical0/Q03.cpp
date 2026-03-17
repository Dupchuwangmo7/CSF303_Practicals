#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string fullName = "Dupchu Wangmo";

    cout << "Full Name       : " << fullName << endl;

    // Total length (including space)
    cout << "Total Length    : " << fullName.length() << endl;

    // Convert to uppercase
    string upper = fullName;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << "Uppercase       : " << upper << endl;

    // Convert to lowercase
    string lower = fullName;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "Lowercase       : " << lower << endl;

    // Initials
    char firstInitial = fullName[0];
    int spacePos = fullName.find(" ");
    char secondInitial = fullName[spacePos + 1];

    cout << "Initials        : " 
         << firstInitial << "." 
         << secondInitial << "." << endl;

    // Length of first name only
    cout << "First Name Len  : " << spacePos << endl;

    return 0;
}
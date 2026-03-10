#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    vector<int> v;
    int value;

    cout << "Enter 6 values: ";

    for(int i = 0; i < 6; i++) {
        cin >> value;
        v.push_back(value);
    }

    cout << "Original  : ";
    for(int x : v)
        cout << x << " ";
    cout << endl;

    // Sort the vector
    sort(v.begin(), v.end());

    cout << "Sorted    : ";
    for(int x : v)
        cout << x << " ";
    cout << endl;

    int minimum = *min_element(v.begin(), v.end());
    int maximum = *max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    float average = sum / 6.0;

    cout << "Min       : " << minimum << endl;
    cout << "Max       : " << maximum << endl;
    cout << "Sum       : " << sum << endl;
    cout << "Average   : " << average << endl;

    // Remove values below average
    v.erase(remove_if(v.begin(), v.end(),
            [average](int x){ return x < average; }),
            v.end());

    cout << "After removing below average:\n";

    for(int x : v)
        cout << x << " ";

    return 0;
}
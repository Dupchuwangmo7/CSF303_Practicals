#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);

    cout << "Enter the numbers: ";

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    cout << "Unique values: ";

    for(int x : arr)
        cout << x << " ";

    return 0;
}
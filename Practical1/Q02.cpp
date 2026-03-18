#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> arr(N);

    cout << "Enter " << N << " integers: ";
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cout << "Reversed: ";
    for(int i = N - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
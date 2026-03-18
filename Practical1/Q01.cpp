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

    int maxVal = arr[0];
    int minVal = arr[0];
    int sum = 0;

    for(int i = 0; i < N; i++){
        if(arr[i] > maxVal) maxVal = arr[i];
        if(arr[i] < minVal) minVal = arr[i];
        sum += arr[i];
    }

    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N;

    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);

    cout << "Enter elements: ";
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int total = 1 << N;
    int count = 0;

    for(int mask = 0; mask < total; mask++) {

        int sum = 0;

        for(int i = 0; i < N; i++) {
            if(mask & (1 << i))
                sum += arr[i];
        }

        if(sum % 2 == 0)
            count++;
    }

    cout << "Number of subsets with even sum: " << count;

    return 0;
}
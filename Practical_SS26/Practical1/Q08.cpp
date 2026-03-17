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

    cout << "Subsets:\n";

    for(int mask = 0; mask < total; mask++) {

        cout << "{ ";

        for(int i = 0; i < N; i++) {
            if(mask & (1 << i))
                cout << arr[i] << " ";
        }

        cout << "}\n";
    }

    return 0;
}
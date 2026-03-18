#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N, K;

    cout << "Enter number of elements (N): ";
    cin >> N;

    cout << "Enter window size (K): ";
    cin >> K;

    vector<int> arr(N);

    cout << "Enter " << N << " elements: ";
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    deque<int> dq;

    cout << "Sliding window maximums: ";

    for(int i = 0; i < N; i++) {

        while(!dq.empty() && dq.front() <= i - K)
            dq.pop_front();

        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= K - 1)
            cout << arr[dq.front()] << " ";
    }

    return 0;
}
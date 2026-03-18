#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    deque<int> dq;

    for(int i = 0; i < N; i++) {

        // Remove elements out of window
        if(!dq.empty() && dq.front() <= i - K)
            dq.pop_front();

        // Remove smaller elements from back
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        // Print max when window is ready
        if(i >= K - 1)
            cout << arr[dq.front()] << " ";
    }

    return 0;
}
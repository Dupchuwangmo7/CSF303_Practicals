#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int N, K;

    cout << "Enter N and K: ";
    cin >> N >> K;

    vector<int> arr(N);

    cout << "Enter " << N << " numbers: ";
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    priority_queue<int> pq;

    for(int x : arr)
        pq.push(x);

    cout << "K largest elements: ";

    for(int i = 0; i < K; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    while(Q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int pos, val;
            cin >> pos >> val;
            arr[pos - 1] = val;
        }
        else {
            int i;
            cin >> i;

            int start = i - K;
            int mx = arr[start];

            for(int j = start; j < i; j++)
                mx = max(mx, arr[j]);

            cout << mx << endl;
        }
    }

    return 0;
}
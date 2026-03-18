#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N, K;
        cin >> N >> K;

        vector<int> arr(N);
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        int result = 0;

        for(int bit = 31; bit >= 0; bit--) {
            int count = 0;

            for(int i = 0; i < N; i++) {
                if((arr[i] & (result | (1 << bit))) == (result | (1 << bit)))
                    count++;
                else
                    count = 0;

                if(count >= K)
                    break;
            }

            if(count >= K)
                result |= (1 << bit);
        }

        cout << result << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& masks, vector<int>& perm) {
    int n = perm.size();

    for(int i = 0; i < n; i++) {
        int a = masks[perm[i]];
        int b = masks[perm[(i + 1) % n]];

        if((a & b) != 0)
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> masks(N);

        for(int i = 0; i < N; i++) {
            int M;
            cin >> M;

            int mask = 0;
            while(M--) {
                int x;
                cin >> x;
                mask |= (1 << x);
            }
            masks[i] = mask;
        }

        // create index array
        vector<int> perm(N);
        for(int i = 0; i < N; i++)
            perm[i] = i;

        bool found = false;

        do {
            if(isValid(masks, perm)) {
                found = true;
                break;
            }
        } while(next_permutation(perm.begin(), perm.end()));

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}
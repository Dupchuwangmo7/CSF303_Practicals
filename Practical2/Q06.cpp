#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> toll(N+1);

    for(int i = 1; i <= N; i++)
        cin >> toll[i];

    const int INF = 1e9;

    vector<vector<int>> dp(N+1, vector<int>(K+1, INF));

    dp[1][0] = 0;

    for(int i = 1; i < N; i++) {
        for(int k = 0; k <= K; k++) {
            if(dp[i][k] == INF) continue;

            // pay
            if(M >= toll[i]) {
                dp[i+1][k] = min(dp[i+1][k], dp[i][k] + 1);
            }

            // skip
            if(k < K) {
                dp[i+1][k+1] = min(dp[i+1][k+1], dp[i][k] + 2);
            }
        }
    }

    int ans = INF;

    for(int k = 0; k <= K; k++)
        ans = min(ans, dp[N][k]);

    if(ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}
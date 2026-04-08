#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0, x;

    // Sum of friends' fingers
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    int countWays = 0;

    // Try all possible values for Dima (1 to 5)
    for (int i = 1; i <= 5; i++) {
        int pos = (sum + i) % (n + 1);

        // If not Dima (position 1 or 0)
        if (pos != 1) {
            countWays++;
        }
    }

    cout << countWays << endl;

    return 0;
}
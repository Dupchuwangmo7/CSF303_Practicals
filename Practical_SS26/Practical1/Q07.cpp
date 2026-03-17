#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    while(n--) {

        int x;
        cin >> x;

        if(left.empty() || x <= left.top())
            left.push(x);
        else
            right.push(x);

        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        else if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }

        if(left.size() == right.size())
            cout << (left.top() + right.top()) / 2.0 << endl;
        else
            cout << left.top() << endl;
    }

    return 0;
}
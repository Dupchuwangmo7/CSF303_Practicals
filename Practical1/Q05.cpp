#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> line;
    int q;

    cout << "Enter number of operations: ";
    cin >> q;

    while(q--) {

        string op;
        cout << "Enter operation: ";
        cin >> op;

        if(op == "push_front") {
            int x;
            cin >> x;
            line.push_front(x);
        }

        else if(op == "push_back") {
            int x;
            cin >> x;
            line.push_back(x);
        }

        else if(op == "pop_front") {
            if(!line.empty())
                line.pop_front();
        }

        else if(op == "pop_back") {
            if(!line.empty())
                line.pop_back();
        }

        cout << "Current line: ";

        for(int x : line)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
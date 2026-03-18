#include <iostream>
using namespace std;

int main() {

    int marks[5] = {85, 72, 90, 65, 78};

    int highest = marks[0];
    int lowest = marks[0];
    int sum = 0;

    
    for(int i = 0; i < 5; i++) {

        sum += marks[i];

        if(marks[i] > highest)
            highest = marks[i];

        if(marks[i] < lowest)
            lowest = marks[i];
    }

    float average = sum / 5.0;

    int aboveAverage = 0;

    cout << "Index  Mark  Bar\n";

    for(int i = 0; i < 5; i++) {

        cout << "[" << i << "]    " << marks[i] << "    ";

        
        for(int j = 0; j < marks[i] / 10; j++) {
            cout << "*";
        }

        cout << endl;

        if(marks[i] > average)
            aboveAverage++;
    }

    cout << "----------------------------------\n";
    cout << "Highest : " << highest << endl;
    cout << "Lowest  : " << lowest << endl;
    cout << "Average : " << average << endl;
    cout << "Above Average: " << aboveAverage << " mark(s)\n";

    return 0;
}
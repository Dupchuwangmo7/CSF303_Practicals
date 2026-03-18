#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int studentNumber;
    vector<float> marks;

public:

    Student(string n, int s) {
        name = n;
        studentNumber = s;
    }

    
    void addMark(float m) {
        marks.push_back(m);
    }

    
    float getAverage() {
        float sum = 0;
        for(float m : marks)
            sum += m;
        return sum / marks.size();
    }

    
    float getHighest() {
        return *max_element(marks.begin(), marks.end());
    }

    
    float getLowest() {
        return *min_element(marks.begin(), marks.end());
    }

    
    void printReport() {

        cout << "================================================\n";
        cout << "  ACADEMIC REPORT\n";
        cout << "================================================\n";

        cout << "Student Name  : " << name << endl;
        cout << "Student No    : 0" << studentNumber << endl;

        cout << "Marks Entered : " << marks.size() << endl;

        cout << "Marks         : ";
        for(float m : marks)
            cout << m << " ";
        cout << endl;

        cout << "Average       : " << getAverage() << endl;
        cout << "Highest       : " << getHighest() << endl;
        cout << "Lowest        : " << getLowest() << endl;

        cout << "================================================\n";
    }
};

int main() {

    Student s("Dupchu Wangmo", 2230282);

    s.addMark(88);
    s.addMark(76);
    s.addMark(91);
    s.addMark(65);
    s.addMark(83);

    s.printReport();

    return 0;
}
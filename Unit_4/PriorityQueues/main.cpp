#include <iostream>
#include <string>
#include <queue>
#include "shp_priority_queue.h"

using namespace std;

struct Student {
    string name;
    int grade;

    Student(string n, int g){
        name = n;
        grade = g;
    }

    bool operator < (const Student& rhs) const {
        return grade < rhs.grade;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    shp_priority_queue students;

    students.push("Neal");
    students.push("Yuvi");
    students.push("Roshan");
    students.push("Nick");

    cout << "The size of the queue is: " << students.size() << endl;

    while (!students.empty()) {
        cout << students.top() << endl;
        students.pop();
    }



    return 0;
}

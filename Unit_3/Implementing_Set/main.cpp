#include <iostream>
#include <vector>
#include "shpset.h"

using namespace std;

int main() {
    cout << "Hello, we're implementing set using a BST!" << endl;
    shpset students;
    students.insert("nick");
    students.insert("neal");
    students.insert("natasha");
    students.insert("thalia");
    students.insert("red");

    if (students.contains("theo")) {
        cout << "Theo is there" << endl;
    }

    if (students.contains("ethan")) {
        cout << "Ethan is there" << endl;
    }

    students.erase("ethan");

    if (students.contains("ethan")) {
        cout << "Ethan is there" << endl;
    }

    vector<string> vec = students.getVector();

    for (string name : vec){
        cout << name << endl;
    }

    return 0;
}

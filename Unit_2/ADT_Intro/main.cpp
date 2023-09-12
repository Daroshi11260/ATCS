#include <iostream>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main() {
    std::cout << "Hello, ADT's!" << std::endl;

    stack<string> s;

    s.push("Red");
    s.push("Natasha");
    s.push("Roshan");

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    queue<string> q;

    q.push("Thalia");
    q.push("Ethan");
    q.push("Neil");

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    set<string> names;

    names.insert("Nick");
    names.insert("Nick");
    names.insert("Nick");
    names.insert("Natasha");
    names.insert("Neil");

    names.erase("Natasha");

    set<string>::iterator itr = names.begin();

    while (itr != names.end()) {
        cout << *itr << endl;
        itr++;
    }

    return 0;
}

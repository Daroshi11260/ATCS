//
// Created by Roshan on 9/20/2023.
//

#include "Homework.h"
#include <set>
#include <stack>
#include <queue>

using namespace std;

Homework::Homework() {
    // :]
}

set<int> Homework::setUnion(set<int> a, set<int> b) {
    set<int> c;
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        // i think you can't do the for each loop with sets
        c.insert(*itr);
    }
    for (auto itr = b.begin(); itr != b.end(); itr++) {
        c.insert(*itr);
    }
    return c;
}

void Homework::removeNegatives(stack<int> &s) {
    stack<int> temp;
    while (!s.empty()) {
        if (s.top() >= 0) {
            temp.push(s.top());
        }
        s.pop();
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

void Homework::reverseQueue(queue<int> &q) {
    stack<int> temp;
    while (!q.empty()) {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty()) {
        q.push(temp.top());
        temp.pop();
    }
}

Homework::~Homework() {
    // :]
}


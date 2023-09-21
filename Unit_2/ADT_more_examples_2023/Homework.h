//
// Created by Roshan on 9/20/2023.
//

#ifndef ADTS_PART_II_HOMEWORK_H
#define ADTS_PART_II_HOMEWORK_H

#include <set>
#include <stack>
#include <queue>

using namespace std;

class Homework {

public:

    Homework();
    //homework
    set<int> setUnion (set<int> a, set<int> b);
    //write a function that removes all negative values from a stack
    void removeNegatives(stack<int> &s);
    //reverse a queue
    void reverseQueue(queue<int> &q);
    ~Homework();

};


#endif //ADTS_PART_II_HOMEWORK_H

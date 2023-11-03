//
// Created by rytan on 11/2/2023.
//

#ifndef PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H
#define PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H

#include <string>
#include <vector>

using namespace std;

class shp_priority_queue {

public:
    shp_priority_queue();
    ~shp_priority_queue();
    void pop();
    void push(string str);
    string top() const;
    int size();
    bool empty();

private:
    vector<string> heap;
    void heapify_up(int index);
    void heapify_down(int index);
    int parent(int index);
    int left_child(int index);
    int right_child(int index);
    bool is_leaf(int index);
    void swap(int index1, int index2);
    void print_heap();

};


#endif //PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H

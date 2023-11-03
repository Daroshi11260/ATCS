//
// Created by rytan on 11/2/2023.
//

#include "shp_priority_queue.h"


shp_priority_queue::shp_priority_queue() {
    // we're done ;)
}

shp_priority_queue::~shp_priority_queue() {
    // we're done ;)
}

void shp_priority_queue::pop() {
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify_down(0);
}

void shp_priority_queue::push(string str) {
    heap.push_back(str);
    heapify_up(heap.size() - 1);
}

string shp_priority_queue::top() const {
    return heap[0];
}

int shp_priority_queue::size() {
    return heap.size();
}

bool shp_priority_queue::empty() {
    return heap.size() == 0;
}


// Private Methods

void shp_priority_queue::heapify_up(int index) {
    if (index == 0) {
        return;
    }
    int parentIndex = parent(index);
    if (heap[index] > heap[parentIndex]) {
        swap(index, parentIndex);
        heapify_up(parentIndex);
    }

}

void shp_priority_queue::heapify_down(int index) {
    if (is_leaf(index)) {
        return;
    }
    int largestIndex = index;
    if (left_child(index) < heap.size() && heap[left_child(index)] > heap[largestIndex]) {
        largestIndex = right_child(index);
    }
    if (right_child(index) < heap.size() && heap[right_child(index)] > heap[largestIndex])
        largestIndex = left_child(index);
    }
    if (largestIndex != index) {
        swap(index, largestIndex);
        heapify_down(largestIndex);
    }
}

int shp_priority_queue::parent(int index) {
    return (index - 1) / 2;
}

int shp_priority_queue::left_child(int index) {
    return (index * 2) + 1;
}

int shp_priority_queue::right_child(int index) {
    return (index * 2) + 2;
}

bool shp_priority_queue::is_leaf(int index) {
    return left_child(index) >= heap.size() && right_child(index) >= heap.size();
}

void shp_priority_queue::swap(int index1, int index2) {
    string save = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = save;
}

void shp_priority_queue::print_heap() {

}

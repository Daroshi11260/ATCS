

#include "shphashtable.h"
#include <string>
#include <iostream>

using namespace std;

shphashtable::shphashtable(int numBuckets) {
    buckets = new Node*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = nullptr;
    }
    size = numBuckets;
}

shphashtable::~shphashtable() {

}

bool shphashtable::contains(string str) {
    return getPointer(str) != nullptr;
}

void shphashtable::put(string str) {

}

void shphashtable::printStats() const {

}

int shphashtable::getHashCode(string str) const {
    hash<string> hashFunction;
    return hashFunction(str) % size;
}

shphashtable::Node *shphashtable::getPointer(string str) const {
    Node* pointer = buckets[getHashCode(str)];
    while (pointer != nullptr){
        if (pointer->value == str){
            return pointer;
        } else {
            pointer = pointer->next;
        }
    }
    return nullptr;
}

void shphashtable::rehash() {

}

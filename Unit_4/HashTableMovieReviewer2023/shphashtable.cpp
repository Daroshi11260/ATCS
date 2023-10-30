

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
    for (int i = 0; i < size; i ++){
        while (buckets[i] != nullptr){
            Node* save = buckets[i]->next;
            delete buckets[i];
            buckets[i] = save;
        }
    }
    delete[] buckets;
}

bool shphashtable::contains(string str) {
    return getPointer(str) != nullptr;
}

void shphashtable::put(string str) {
    if (contains(str))
        return;
    int index = getHashCode(str);
    Node* save = buckets[index];
    buckets[index] = new Node();
    buckets[index]->value = str;
    buckets[index]->next = save;
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

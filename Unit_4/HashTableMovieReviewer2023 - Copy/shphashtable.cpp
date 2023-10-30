

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

bool shphashtable::contains(string str) const{
    return getPointer(str) != nullptr;
}

void shphashtable::put(string str, int rating) {
    Node* pointer = getPointer(str);
    if (pointer == nullptr) {
        int index = getHashCode(str);
        Node *save = buckets[index];
        buckets[index] = new Node(str, rating);
        buckets[index]->next = save;
    } else {
        pointer->value.addScore(rating);
    }
}



void shphashtable::printStats() const {
    cout << "NUM BUCKETS = " << size << endl;
    cout << "TOTAL WORDS = " << getTotalWordCount() << endl;
    cout << "NUM EMPTY BUCKETS = " << getEmptyBucketCount() << endl;
    cout << "LONGEST CHAIN = " << getLongestChainLength() << endl;

}

int shphashtable::getHashCode(string str) const {
    hash<string> hashFunction;
    return hashFunction(str) % size;
}

shphashtable::Node *shphashtable::getPointer(string str) const {
    Node* pointer = buckets[getHashCode(str)];
    while (pointer != nullptr){
        if (pointer->value.getWord() == str){
            return pointer;
        } else {
            pointer = pointer->next;
        }
    }
    return nullptr;
}

double shphashtable::getAverageRating(string str) const {
    return contains(str) ? getPointer(str)->value.getAvgScore() : 2.0;
}

void shphashtable::rehash() {
    
}

int shphashtable::getTotalWordCount() const {
    int totalWordCount = 0;
    for (int i = 0; i < size; i ++){
        while (buckets[i] != nullptr){
            totalWordCount += 1;
            buckets[i] = buckets[i]->next;
        }
    }
    return totalWordCount;
}

int shphashtable::getLongestChainLength() const {
    int longest = 0;
    for (int i = 0; i < size; i++){
        int length = 0;
        Node* pointer = buckets[i];
        while (pointer != nullptr){
            length += 1;
            pointer = pointer->next;
        }
        if (length > longest){
            longest = length;
        }
    }
    return longest;
}


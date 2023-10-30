

#ifndef HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#define HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#include <string>
#include <utility>
#include "WordEntry.h"

using namespace std;

class shphashtable {

public:
    shphashtable(int numBuckets);
    ~shphashtable();
    bool contains(string str) const;
    void put(string str, int rating);
    void printStats() const;
    double getAverageRating(string str) const;

private:
    struct Node {
        WordEntry value;
        Node* next;
        Node(string str, int rating):value(str, rating) {
            next == nullptr;
        }
    };
    Node** buckets = nullptr;
    int size;
    int getHashCode(string str) const;
    Node* getPointer(string str) const;
    void rehash();
    int getTotalWordCount() const;
    int getLongestChainLength() const;
    int getEmptyBucketCount() const;

};


#endif //HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H

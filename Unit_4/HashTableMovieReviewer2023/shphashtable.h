

#ifndef HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#define HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#include <string>
using namespace std;

class shphashtable {

public:
    shphashtable(int numBuckets);
    ~shphashtable();
    bool contains(string str);
    void put(string str);
    void printStats() const;

private:
    struct Node {
        string value;
        Node* next;
    };
    Node** buckets = nullptr;
    int size;
    int getHashCode(string str) const;
    Node* getPointer(string str) const;
    void rehash();

};


#endif //HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H

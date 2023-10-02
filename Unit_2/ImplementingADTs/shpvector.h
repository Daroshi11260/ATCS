//
// Created by rytan on 9/26/2023.
//

#ifndef IMPLEMENTINGADTS_SHPVECTOR_H
#define IMPLEMENTINGADTS_SHPVECTOR_H


template<typename ElemType>
class shpvector {
public:
    shpvector();
    ~shpvector();
    void push_back(ElemType val);
    void erase(int index);
    void insert(int index, ElemType val);
    void clear();
    ElemType set(int index, ElemType val);
    ElemType at(int index);
    int size();


private:
    int capacity;
    int length;
    ElemType* arr[];
};

#include "shpvector.cpp"

#endif //IMPLEMENTINGADTS_SHPVECTOR_H

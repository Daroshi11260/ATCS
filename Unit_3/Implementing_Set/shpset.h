//
// Created by rytan on 10/9/2023.
//

#ifndef IMPLEMENTING_SET_SHPSET_H
#define IMPLEMENTING_SET_SHPSET_H

#include <vector>
#include <iostream>

using namespace std;

class shpset {
public:
    shpset();
    ~shpset();
    void insert(string name);
    bool contains(string name);
    void erase(string name);
    const int size();
    vector<string> getVector();
    void clear();
private:
    struct node {
        string name;
        node *left;
        node *right;

        node(){
            left = nullptr;
            right = nullptr;
        }
    };
    node *root;
    void insert(string name, node* &tree);
    bool contains(string name, node* tree);
    node* erase(string name, node* tree);
    vector<string> getVector(vector<string> &result, node* tree) const;
    void clear(node* tree);
    const int size(node* tree);
};


#endif //IMPLEMENTING_SET_SHPSET_H

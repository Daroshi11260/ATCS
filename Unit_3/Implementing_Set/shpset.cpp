//
// Created by rytan on 10/9/2023.
//

#include "shpset.h"

shpset::shpset() {
    root = nullptr;
}

shpset::~shpset() {
    clear();
}

void shpset::insert(string name) {
    if (root != nullptr) {
        insert(name, root);
    } else {
        root = new node;
        root->name = name;
    }
}

bool shpset::contains(string name) {
    return contains(name, root);
}

void shpset::erase(string name) {
    erase(name, root);
}

const int shpset::size() {
    return size(root);
}

vector<string> shpset::getVector() {
    vector<string> result;
    getVector(result, root);
    return result;
}

void shpset::clear() {
    clear(root);
}






void shpset::insert(string name, shpset::node* &tree) {
    if (tree == nullptr){
        tree = new node;
        tree->name = name;
    } else if (tree->name == name){
        return;
    } else if (tree->name > name){
        insert(name, tree->left);
    } else {
        insert(name, tree->right);
    }
}

bool shpset::contains(string name, shpset::node *tree) {
    if (tree == nullptr){
        return false;
    } else if (tree->name == name){
        return true;
    } else if (tree->name > name){
        return contains(name, tree->left);
    } else {
        return contains(name, tree->right);
    }
}

shpset::node* shpset::erase(string name, shpset::node *tree) {
    if (tree == nullptr){
        return nullptr;
    } else if (tree->name > name){
        erase(name, tree->left);
    } else if (tree->name < name){
        erase(name, tree->right);
    } else {
        if (tree->left == nullptr){
            node* save = tree->right;
            delete tree;
            return save;
        } else if (tree->right == nullptr){
            node* save = tree->left;
            delete tree;
            return save;
        } else {
            node* save = tree->left;
            while (save->right != nullptr){
                save = save->right;
            }
            tree->name = save->name;
            tree->right = erase(save->name, tree->left);
        }
    }
    return tree;
}

vector<string> shpset::getVector(vector<string> &result, shpset::node *tree) const {
    if (tree == nullptr){
        return result;
    } else {
        getVector(result, tree->left);
        result.push_back(tree->name);
        getVector(result, tree->right);
    }
}

void shpset::clear(shpset::node *tree) {
    if (tree == nullptr){
        return;
    } else {
        clear(tree->left);
        clear(tree->right);
        delete tree;
    }
}

const int shpset::size(shpset::node *tree) {
    if (tree == nullptr) {
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
}

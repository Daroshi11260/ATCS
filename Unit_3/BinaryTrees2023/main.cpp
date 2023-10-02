#include <iostream>
using namespace std;

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeStudentTree() {
    TreeNode *temp = new TreeNode;
    temp->value = "Nick";
    temp->left = new TreeNode;
    temp->left->value = "Natasha";
    temp->left->right = new TreeNode;
    temp->left->right->value = "Neal";
    temp->left->left = new TreeNode;
    temp->left->left->value = "Ethan";
    temp->left->left->right = new TreeNode;
    temp->left->left->right->value = "Kevin";
    temp->right = new TreeNode;
    temp->right->value = "Roshan";
    temp->right->left = new TreeNode;
    temp->right->left->value = "Redmond";
    temp->right->right = new TreeNode;
    temp->right->right->value = "Thalia";
    return temp;
}


int main() {
    cout << "Hello, Binary Trees!" << endl;
    TreeNode *root = makeStudentTree();
    return 0;
}

#include <iostream>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int countFavouriteNumbers(TreeNode *root, set<int> &favouriteNumbers);

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

int countFavouriteNumbers(TreeNode *root, set<int> &favouriteNumbers) {
    if (root == nullptr) {
        return 0;
    }
    if (favouriteNumbers.count(root->val) == 1) {
        return 1 + countFavouriteNumbers(root->left, favouriteNumbers)
                 + countFavouriteNumbers(root->right, favouriteNumbers);
    }

    return 0 + countFavouriteNumbers(root->left, favouriteNumbers) 
             + countFavouriteNumbers(root->right, favouriteNumbers);
}


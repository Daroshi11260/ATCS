#include <iostream>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){left=nullptr;right=nullptr;}
};

int countFavouriteNumbers(TreeNode *root, set<int> &favouriteNumbers);

bool hasPathSum(TreeNode* root, int sum);

int getLevelSumDifference(TreeNode* root);

int main() {
    cout << "Hello, World!" << endl;

    set<int> nums = {1, 2, 3, 4, 5};

    TreeNode* root = new TreeNode();
    root->val = 27;
    root->left = new TreeNode();
    root->left->val = 2;
    root->right = new TreeNode();
    root->right->val = 3;

    cout << countFavouriteNumbers(root, nums) << endl;

    if (hasPathSum(root, 30)) {
        cout << "Has path sum" << endl;
    } else {
        cout << "Does not have path sum" << endl;
    }

    cout << getLevelSumDifference(root) << endl;

    return 0;
}

int countFavouriteNumbers(TreeNode* root, set<int> &favouriteNumbers) {
    if (root == nullptr) {
        return 0;
    }
    return favouriteNumbers.count(root->val)
            + countFavouriteNumbers(root->left, favouriteNumbers)
            + countFavouriteNumbers(root->right, favouriteNumbers);
}

bool hasPathSum(TreeNode* root, int sum){
    return root == nullptr ? sum == 0 : hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}


int getLevelSumDifference(TreeNode* root){
    if (root == nullptr) {
        return 0;
    }
    return root->val - getLevelSumDifference(root->left) - getLevelSumDifference(root->right);
}

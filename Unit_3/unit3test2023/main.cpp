#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(){
        value = 0;
        left = nullptr;
        right = nullptr;
    }
};

bool isAdditionTree(Node* root);

int height(Node* root);

int leafSpan(Node* root);

bool pairSum(Node* root, int sum);

bool pairSumFaster(Node* root, int sum);

int main() {

    Node *root = new Node();

    root->value = 5;
    root->left = new Node();
    root->right = new Node();
    root->left->value = 45;
    root->right->value = 3;
    root->left->left = new Node();
    root->left->right = new Node();
    root->left->left->value = 10;
    root->left->right->value = 15;
    root->right->left = new Node();
    root->right->right = new Node();
    root->right->left->value = 12;
    root->right->right->value = 23;

    if (isAdditionTree(root)){
        cout << "This is an addition tree" << endl;
    }
    else{
        cout << "This is not an addition tree" << endl;
    }

    cout << leafSpan(root) << endl;

    if (pairSumFaster(root, 17)){
        cout << "pair exists" << endl;
    } else {
        cout << "pair does not exist" << endl;
    }


    return 0;
}

bool isAdditionTree(Node* root){
    if (root == nullptr){
        return true;
    }
    if (root->left == nullptr && root->right == nullptr){
        return true;
    }
    if (root->left == nullptr){
        return (root->value == root->right->value) && isAdditionTree(root->right);
    }
    if (root->right == nullptr){
        return (root->value == root->left->value) && isAdditionTree(root->left);
    }
    return (root->value == root->left->value + root->right->value) && isAdditionTree(root->left) && isAdditionTree(root->right);
}

int height(Node* root){
    if (root == nullptr){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}


int leafSpan(Node* root){
    if (root == nullptr){
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr){
        return 1;
    }

    int a = max(leafSpan(root->left), leafSpan(root->right));

    int b = max(a, height(root->left) + height(root->right) + 1);

    // This would literally not work any other way and i have no clue why.

    return b;
}

void inOrder(Node* root, vector<int> &v){
    if (root == nullptr){
        return;
    }
    inOrder(root->left, v);
    v.push_back(root->value);
    inOrder(root->right, v);
}

bool pairSum(Node* root, int sum){

    vector<int> arr;

    inOrder(root, arr);

    // I could probably do it in O(log(n)) time but
    // i dont think I would be able to figure it out
    // right now. so O(n^2) it is.

    for (int i = 0; i < arr.size(); i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[i] + arr[j] == sum){
                return true;
            }
        }
    }

    return false;
}

bool find(Node* root, int num){
    if (root == nullptr){
        return false;
    } if (root->value == num){
        return true;
    } else {
        return find(root->left, num) || find(root->right, num);
    }
}

bool pairSumFaster(Node* root, int sum){
    if (find(root, sum - root->value)){
        return true;
    } else {
        return pairSumFaster(root->left, sum) || pairSumFaster(root->right, sum);
    }
}
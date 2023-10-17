#include <iostream>
#include <stack>
using namespace std;

struct EComponent {
    string op;
    int number;
};

struct ETNode {
    ETNode *left, *right;
    EComponent value;
    ETNode(string oper) {
        value.op = oper;
        left = nullptr;
        right = nullptr;
    }
    ETNode(int num) {
        value.op = "#";
        value.number = num;
        left = nullptr;
        right = nullptr;
    }
    string tostring() {
        if (value.op != "#")
            return value.op;
        else
            return to_string(value.number);
    }
};

ETNode *buildExpressionTree() {
    ETNode *tree = new ETNode("*");
    tree->left = new ETNode("+");
    tree->left->left = new ETNode(2);
    tree->left->right = new ETNode(1);
    tree->right = new ETNode("-");
    tree->right->left = new ETNode("/");
    tree->right->left->left = new ETNode(60);
    tree->right->left->right = new ETNode(4);
    tree->right->right = new ETNode(6);
    return tree;
}


void printInOrder(ETNode *root) {
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->tostring() << " ";
    printInOrder(root->right);
}

void printPostOrder(ETNode *root) {
    if (root == nullptr)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->tostring() << " ";
}

void eval (ETNode *root) {
    if (root == nullptr || root->tostring() == "#")
        return;
    eval(root->left);
    eval(root->right);
    if (root->tostring() == "+") {
        root->value.number = root->left->value.number + root->right->value.number;
    } else if (root->tostring() == "-") {
        root->value.number = root->left->value.number - root->right->value.number;
    } else if (root->tostring() == "*") {
        root->value.number = root->left->value.number * root->right->value.number;
    } else if (root->tostring() == "/") {
        root->value.number = root->left->value.number / root->right->value.number;
    }

    root->value.op = "#";

    delete root->left;
    delete root->right;
    root->left = nullptr;
    root->right = nullptr;
}

int main() {
    cout << "Hello, Expression Tree!" << endl;
    ETNode *root = buildExpressionTree();
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    eval(root);
    if (root->value.number == (2 + 1) * (60 / 4 - 6))
        cout << "Correct!" << endl;
    else
        cout << "Wrong!" << endl;

    return 0;
}
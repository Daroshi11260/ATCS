
#ifndef HUFFMAN_YOUR_HUFFMAN_CODE_H
#define HUFFMAN_YOUR_HUFFMAN_CODE_H

#include <map>
#include "huffman_helper.h"
using namespace std;

struct TreeNode {
    char ch;
    int weight;
    TreeNode *left;
    TreeNode *right;
};
struct CompareTreeNode
{
    bool operator()(const TreeNode* lhs, const TreeNode* rhs) const
    {
        return lhs->weight > rhs->weight;
    }
};
/* You need the unusual CompareTreeNode struct above if you want to make
 * a priority queue of TreeNodes.  (Hint: You do!)  This struct defines an
 * operator for comparing TreeNode*, which makes it possible for the
 * underlying heap for a priority queue to work correctly.  It's weird,
 * but here's the syntax you'll need:
       priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> pq;
 * The first parameter describes what it is a priority queue of, the
 * second parameter describes the underlying heap implementation ("I'm
 * using a vector for this heap"), and the third parameter specifies a
 * way to compare TreeNode*.  Phew...
 */

// NOTE: The struct EncodedData is defined in the huffman_helper.h file

map<char, int> freqMap(string &text);

priority_queue<TreeNode *, vector<TreeNode *>, CompareTreeNode> makePriorityQueue(map<char, int> &fm);

void huffmanAlgo(priority_queue<TreeNode *, vector<TreeNode *>, CompareTreeNode> &pq);

void addPaths(TreeNode* root, map<char, queue<Bit>> &pathMap, queue<Bit> path);

queue<Bit> createEncodedData (map<char, queue<Bit>> &pathMap, string &text, TreeNode* root);

void flattenTree(TreeNode* root, EncodedData & data);

EncodedData compress(string text) {

    map<char, int> fm = freqMap(text);

    priority_queue<TreeNode *, vector<TreeNode *>, CompareTreeNode> pq = makePriorityQueue(fm);

    huffmanAlgo(pq);

    TreeNode* root = pq.top();

    map<char, queue<Bit>> pathMap;

    addPaths(root, pathMap, queue<Bit>());

    queue<Bit> encoded = createEncodedData(pathMap ,text, root);

    EncodedData data;

    data.messageBits = encoded;

    queue<char> leaves;
    queue<Bit> shape;

    flattenTree(root, data);


    EncodedData result;
    // you've got a lot to write here
    return result;
}

queue<Bit> createEncodedData(map<char, queue<Bit>> &pathMap, string &text, TreeNode* root){
    queue<Bit> encoded;
    for (char ch: text){
        queue<Bit> path = pathMap[ch];
        while(!path.empty()){
            encoded.push(path.front());
            path.pop();
        }
    }
    return encoded;
}

void flattenTree(TreeNode* root, EncodedData & data){
    if (root->right == nullptr && root->left == nullptr){
        data.treeLeaves.push(root->ch);
        data.treeShape.push(0);
        return;
    } else {
        data.treeShape.push(1);
        flattenTree(root->left, data);
        flattenTree(root->right, data);
    }

}

void addPaths(TreeNode* root, map<char, queue<Bit>> &pathMap, queue<Bit> path){
    if (root-> right == nullptr && root->left == nullptr){
        pathMap[root->ch] = path;
        return;
    }

    if (root -> left != nullptr){
        queue<Bit> leftPath = path;
        leftPath.push(0);
        addPaths(root->left, pathMap, leftPath);
    }

    if (root -> right != nullptr){
        queue<Bit> rightPath = path;
        rightPath.push(1);
        addPaths(root->right, pathMap, rightPath);
    }
}

void huffmanAlgo(priority_queue<TreeNode *, vector<TreeNode *>, CompareTreeNode> &pq) {
    while(pq.size() > 1){
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();

        TreeNode* parent = new TreeNode;
        parent->weight = left->weight + right->weight;
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }
}

priority_queue<TreeNode *, vector<TreeNode *>, CompareTreeNode> makePriorityQueue(map<char, int> &fm) {
    priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> pq;
    for (auto it = fm.begin(); it != fm.end(); it++){
        TreeNode* node = new TreeNode;
        node->ch = it->first;
        node->weight = it->second;
        node->left = nullptr;
        node->right = nullptr;
        pq.push(node);
    }
    return pq;
}

map<char, int> freqMap(string &text) {

    map<char, int> fm;

    for (char ch: text){
        fm[ch]++;
    }
    return fm;
}

int size(TreeNode* root){
    if (root == nullptr) return 0;

    return size(root->left) + size(root->right) + 1;
}

TreeNode* treeBuildingHelper(EncodedData& data){
    if(data.treeLeaves.empty()) return nullptr;

    TreeNode* root = new TreeNode;
    if(data.treeShape.front() == 0) {
        data.treeShape.pop();
        root->ch = data.treeLeaves.front();
        root->left = nullptr;
        root->right = nullptr;
        data.treeLeaves.pop();
    } else {
        data.treeShape.pop();
        root->left = treeBuildingHelper(data);
        root->right = treeBuildingHelper(data);
    }
    return root;
}

string decompress(EncodedData& data) {
    //build huffman tree
    TreeNode* root = treeBuildingHelper(data);
    string result = "";

    cout << "size : " << size(root) << endl;
    while(!data.messageBits.empty()){
        TreeNode* cur = root;
        while(cur->left != nullptr && cur->right != nullptr){
            if(data.messageBits.front() == 0)
                cur = cur->left;
            else
                cur = cur->right;
            data.messageBits.pop();
        }
        result += cur->ch;
    }

    return result;
}



#endif //HUFFMAN_YOUR_HUFFMAN_CODE_H

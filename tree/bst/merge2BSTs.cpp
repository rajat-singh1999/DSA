#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{

    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};

void inorder(TreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void mergeVectors(vector<int> v1, vector<int> v2, vector<int> &ino) {
    ino.reserve(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ino));
}

TreeNode<int> *inorderToBST(vector<int> &ino, int s, int e){
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(ino[mid]);
    root->left = inorderToBST(ino, s, mid-1);
    root->right = inorderToBST(ino, mid+1, e);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> in1;
    vector<int> in2;
    inorder(root1, in1);
    inorder(root2, in2);

    vector<int> ino;
    mergeVectors(in1, in2, ino);
    
    int s = 0;
    int e = ino.size()-1;
    return inorderToBST(ino, s, e);
}
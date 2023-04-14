#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> v){
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(v[mid]);
    root->left = inorderToBST(s, mid-1, v);
    root->right = inorderToBST(mid+1, e, v);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    inorder(root, v);

    return inorderToBST(0, v.size()-1, v);
}

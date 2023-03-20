#include <bits/stdc++.h> 
using namespace std;
    
template <typename T>
class TreeNode {
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
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


void inOrder(TreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> v;
    inOrder(root, v);
    int n = v.size();

    TreeNode<int>* newRoot = new TreeNode<int>(v[0]);
    TreeNode<int>* curr = newRoot;

    for(int i=1;i<=n-1;i++){
        TreeNode<int>* temp = new TreeNode<int>(v[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

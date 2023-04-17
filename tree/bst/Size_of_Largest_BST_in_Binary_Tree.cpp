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

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curNode;
    curNode.size = left.size + right.size + 1;
    curNode.maxi = max(root->data, right.maxi);
    curNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
        curNode.isBST = true;
    }
    else
        curNode.isBST = false;
    
    if(curNode.isBST)
        ans = max(ans, curNode.size);
    
    return curNode;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
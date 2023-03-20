#include <bits/stdc++.h> 
using namespace std;

template <typename T>

class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int minVal(BinaryTreeNode<int> *root){
    int min = root->data;
    while(root->left){
        min = root->left->data;
        root = root->left;
    }
    return min;
}

int maxVal(BinaryTreeNode<int> *root){
    int max = root->data;
    while(root->right){
        max = root->right->data;
        root = root->right;
    }
    return max;
}

BinaryTreeNode<int>* searchNode(BinaryTreeNode<int> *root, int k){
    if(root == NULL)
        return root;
    
    if(root->data == k){
        return root;
    }
    if(k<root->data)
        searchNode(root->left, k);
    else
        searchNode(root->right, k);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int> *temp = root;
    int pred = -1;
    int suc = -1;

    while(temp->data != key){
        if(temp->data >key){
            suc = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data; 
            temp = temp->right;
        }
    }
    pair<int, int> ans = make_pair(pred, suc);
    if(temp->left != NULL)
        ans.first = maxVal(temp->left);

    if(temp->right != NULL)
        ans.second = minVal(temp->right);

    return ans;
}

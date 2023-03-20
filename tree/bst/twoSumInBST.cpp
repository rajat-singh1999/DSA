#include <bits/stdc++.h> 
using namespace std;

template <typename T>

class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inOrder(BinaryTreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> v;
    inOrder(root, v);

    int i = 0, j = v.size()-1;
    while(i<j){
        int sum = v[i] + v[j];
        if(sum == target)
            return true;
        else{
            if(sum < target)
                i++;
            else
                j--;
        }
    }
    return false;
}
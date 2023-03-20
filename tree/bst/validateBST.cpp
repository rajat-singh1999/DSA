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
};


void solve(BinaryTreeNode<int> *root, int &prev, int &ans){
    if(root == NULL){
        return ;
    }
    
    
    solve(root->left, prev , ans);

    //cout<<root->data<<endl<<"prev:"<<prev<<endl;
    if(root->data < prev){
        ans = 0;
        //  cout<<"hi"<<endl;
    }
    prev = root->data;

    solve(root->right, prev, ans);
}

bool isBST(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL)
        return true;

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}


bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    int prev = INT_MIN;
    int ans = 1;
    solve(root, prev, ans);
    if(ans == 1)
        return true;
    else
        return false;

}

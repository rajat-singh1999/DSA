#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Node(){
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

Node<int>* solve(vector<int> &preorder, int mini, int maxi, int &i){
    if((i >= preorder.size()) || (preorder[i]<mini || preorder[i]>maxi))
        return NULL;

    Node<int>* root = new Node<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

Node<int>* preorderToBST(vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}
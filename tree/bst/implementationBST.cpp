#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int d){
    if(root == NULL){
        Node* newNode = new Node(d);
        root = newNode;
        return root;
    }
    if(d<root->data)
        root->left = insert(root->left, d);
    
    if(d>=root->data)
        root->right = insert(root->right, d);
    
    return root;
}

void preorder(Node* root){
    if(root == NULL)
        return ;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL)
        return ;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return ;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int minVal(Node* root){
    int min  = root->data;
    while(root->left){
        min = root->left->data;
        root = root->left;
    }
    return min;
}

int maxVal(Node* root){
    int max = root->data;
    while(root->right){
        max = root->right->data;
        root = root->right;
    }
    return max;
}

Node* deleteNode(Node* root, int d){
    if(!root)
        return root;
    if(d<root->data)
        root->left = deleteNode(root->left, d);
    else if(d>root->data)
        root->right = deleteNode(root->right, d);

    else{
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        
        root->data = minVal(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

int search(Node* root, int d){
    if(root == NULL)
        return 0;
    else if(root->data == d)
        return 1;
    else if(d > root->data)
        return search(root->right, d);
    else
        return search(root->left, d);
}

int main(){
    Node* root = NULL;

    root = insert(root, 17);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 18);
    root = insert(root, 22);
    root = insert(root, 21);

    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    root = deleteNode(root, 17);
    preorder(root);
    cout<<endl;
    cout<<search(root, 21)<<endl;
    cout<<search(root, 100)<<endl;
    cout<<search(root, 2)<<endl;
    cout<<search(root, -7)<<endl;
    return 0;
}
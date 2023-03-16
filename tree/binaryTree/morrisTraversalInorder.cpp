#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void morris(Node* root){
    Node* curr = root;

    while(curr!=NULL){
        if(!curr->left){
            cout<<curr->data<<" ";
            curr = curr->right;
        }

        else{
            Node* pred = curr->left;
            while(pred->right!=NULL && pred->right != curr)
                pred = pred->right;
            
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right =NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

void morrisPre(Node* root){
    Node* curr = root;

    while(curr!=NULL){
        if(!curr->left){
            cout<<curr->data<<" ";
            curr = curr->right;
        }

        else{
            Node* pred = curr->left;
            while(pred->right!=NULL && pred->right != curr)
                pred = pred->right;
            
            if(pred->right == NULL){
                pred->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }
            else{
                pred->right =NULL;
                curr = curr->right;
            }
        }
    }
}

void morrisPost(Node* root){
    Node* curr = root;
    vector<int> ans;

    while(curr!=NULL){
        if(!curr->right){
            ans.push_back(curr->data);
            curr = curr->left;
        }

        else{
            Node* pred = curr->right;
            while(pred->left!=NULL && pred->left != curr)
                pred = pred->left;
            
            if(pred->left == NULL){
                pred->left = curr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                pred->left =NULL;
                curr = curr->left;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for(auto i: ans){
        cout<<i<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(6);

    morris(root);
    cout<<endl;
    morrisPre(root);
    cout<<endl;
    morrisPost(root);
    return 0;
}
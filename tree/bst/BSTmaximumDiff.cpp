//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    pair<Node*,int> check(Node* root,int target){
        if(root==NULL) return {NULL,0};
        if(root->data==target) return {root,target};
        if(target<root->data){
            if(root->left){
                pair<Node*,int> temp=check(root->left,target);
                return {temp.first,temp.second+root->data};
            }
        }
        else if(target>root->data){
            if(root->right){
                pair<Node*,int> temp=check(root->right,target);
                return {temp.first,temp.second+root->data};
            }
        }
        return {NULL,0};
    }
    void ans(Node* root,int beforet,int& res){
        if(!root->left && !root->right){
            res=max(res,beforet);
        }
        if(root->left){
           ans(root->left,beforet-root->left->data,res); 
        }
        if(root->right){
            ans(root->right,beforet-root->right->data,res);
        }
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int beforet;
        pair<Node*,int> t=check(root,target);
        if(t.first==NULL) return -1;
        else{
            beforet=t.second-target;
        }
       int res=INT_MIN;
       ans(t.first,beforet,res);
       return res;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
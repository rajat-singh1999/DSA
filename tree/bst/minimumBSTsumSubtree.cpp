/*
Given a binary tree and a target, find the number of node in the minimum sub-tree with the given sum equal to the target which is also a binary search tree.

Example 1:
Input:
           13
         /    \
       5       23
      / \      / \
     N   17   N   N
         /
        16
Target: 38
Output: 3
Explanation: 5,17,16 is the smallest subtree
with length 3.
 

Example 2:
Input:
             7
           /   \
          N    23
             /   \
            10    23
           /  \   / \
          N   17 N   N
Target: 73
Output: -1
Explanation: No subtree is bst for the given target.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minSubtreeSumBST() which takes the tree root and target as input parameters which is a binary Tree and returns the length of the minimum subtree having a sum equal to the target but which is a binary search tree.

Expected Time Complexity: O(N), where N is no. of nodes
Expected Space Complexity: O(h), where h is the height of the tree

Constraints:
1 <= N <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool isbst(Node *root,int &le,int left,int right){
        if(!root)return true;
        le+=1;
        if(root->data<=left || root->data>right)
            return false;
        bool t=false,tt=false;
        t=isbst(root->left,le,left,root->data);
        tt=isbst(root->right,le,root->data,right);
        return t&&tt;
    }
    int summ(Node *root,int &id,int &target){
        if(!root)return 0;
        int l=0,r=0;
        if(root->left)
            l=summ(root->left,id,target);
        if(root->right)
            r=summ(root->right,id,target);
        int le=0;
        if(l+r+root->data==target && isbst(root,le,INT_MIN,INT_MAX)){
            id=min(le,id);
        }
        return l+r+root->data;
    }
    int minSubtreeSumBST(int target, Node *root) {
        int id=INT_MAX;
        summ(root,id,target);
        return id==INT_MAX?-1:id;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* addNode(Node* tail, int d){
    Node* newnode = new Node(d);

    if(tail == NULL){
        newnode->next = newnode;
        tail = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
    return tail;
}

int show(Node* tail){
    int c=0;
    if(tail == NULL)
        cout<<"SLL is empty!"<<endl;
    else{
        Node* temp = tail->next;
        do{
            cout<<temp->data<<" ->";
            c++;
            temp = temp->next;
        }while(temp!=tail->next);
        cout<<endl;
    }
    return c;
}


pair<Node*, Node*> split(Node* tail, int n){
    pair<Node*, Node*> ans;
    if(tail == NULL){
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    else{
        int k = (n%2==0)?(n/2):(n/2)+1;
        int c = 1;
        Node* temp = tail->next;
        while(c!=k){
            temp = temp->next;
            c++;
        }
        Node* q = temp->next;
        temp->next = tail->next;
        ans.first = temp;

        tail->next = q;
        ans.second = tail;
        return ans;
    }
}

int main(){

    Node* tail = NULL;
    int size;
    size = show(tail);

    tail = addNode(tail, 20);
    tail = addNode(tail, 30);
    tail = addNode(tail, 40);
    tail = addNode(tail, 50);
    tail = addNode(tail, 10);
    tail = addNode(tail, 60);
    tail = addNode(tail, 70);

    size = show(tail);

    pair<Node*, Node*> ans = split(tail, size);
    size = show(ans.first);
    size = show(ans.second);

    return 0;
}
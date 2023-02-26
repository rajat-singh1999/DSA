#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* arb;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};

void printList(Node* head){
    if(head!=NULL){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<endl;
    }
    else
        cout<<"Nothing to print!"<<endl;
}

Node* insertAtEnd(Node* &head, int d){
    Node* newnode = new Node(d);
    if(head == NULL){
        head = newnode;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}


Node* mergeSort(Node* &head) {
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    Node* mid = findMid(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halves
    Node* result = merge(left, right);
    head = result;
    return head;
}

int main(){

    Node* head = NULL;
    insertAtEnd(head, 27);
    insertAtEnd(head, 42);
    insertAtEnd(head, 15);
    insertAtEnd(head, 3);
    insertAtEnd(head, 66);
    
    printList(head);

    mergeSort(head);

    printList(head);
    return 0;
}
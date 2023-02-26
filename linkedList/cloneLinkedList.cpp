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

Node* insertAtHead(Node* &head, int d){
    Node* newnode = new Node(d);
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    return head;
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

void putRandom(Node* &head, int from, int to){
    
    Node* p = head;
    Node* q = head;
    int c=1;
    while(c!=to){
        q = q->next;
        c++;
    }

    c=1;
    while(c!=from){
        p = p->next;
        c++;
    }

    p->arb = q;
}

void printRandoms(Node* head){
    if(head == NULL)
        cout<<"Nothing to print"<<endl;

    else{
        cout<<"From print: "<<endl;
        Node* p=head;
        while(p!=NULL){
            if(p->arb!=NULL)
                cout<<p->data<<" points to "<<p->arb->data<<endl;
            p = p->next;
        }
    }
}

void printRandom(Node* head) {
    while(head != NULL) {
        cout << " head data: " << head->data <<" ";
        if(head ->arb != NULL) {
            cout << " head random data " << head -> arb ->data;
        }
        else
        {
            cout << " head random data: NULL";
        }
        head = head -> next;
        cout << endl;
    }
}

Node *copyList(Node *head)
{
    //step 1: Create a Clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    Node* temp = head;
    while(temp != NULL) {
        insertAtEnd(cloneHead, temp->data);
        temp = temp -> next;
    }
    
    // step 2: insert nodes of Clone List in between originalList
    
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while(originalNode != NULL && cloneNode != NULL) {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;
        
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode  = next;
    }
    
    // step 3: Random pointer copy
    originalNode = head;
    cloneNode = cloneHead;
    
    while(originalNode != NULL && cloneNode != NULL) { 
        
        if(originalNode -> arb != NULL) {
            cloneNode -> arb = originalNode -> arb -> next;
        }
        else
        {
            cloneNode -> arb  = NULL;
        }
        if(cloneNode->next!=NULL){
            cloneNode = cloneNode -> next ->next;
        }
        else{
            cloneNode = cloneNode -> next;
        }
            originalNode = originalNode -> next ->next;
    }
    
    //step 4: revert step 2 changes
    Node* original = head;
    Node* copy = cloneHead;
    
        while (original && copy)
        {
            original->next =
                original->next? original->next->next : original->next;
        
            copy->next = copy->next?copy->next->next:copy->next;
            original = original->next;
            copy = copy->next;
        }

    // step 5 answer return
    return cloneHead;
}

int main(){

    Node* headOG = NULL;
    insertAtEnd(headOG, 1);
    insertAtEnd(headOG, 2);
    insertAtEnd(headOG, 3);
    insertAtEnd(headOG, 4);
    insertAtEnd(headOG, 5);
    
    printList(headOG);

    putRandom(headOG, 1, 3);
    putRandom(headOG, 2, 1);
    putRandom(headOG, 3, 4);
    putRandom(headOG, 4, 2);
    putRandom(headOG, 5, 3);

    printRandom(headOG);

    Node* clone = NULL;
    clone = copyList(headOG);
    printList(clone);
    printRandom(clone);

    return 0;
}
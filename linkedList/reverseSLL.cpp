#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class SLL{
    public:
    Node* head;
    int length;

    SLL(){
        length = 0;
        head = NULL;
    }

    void printList(){
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

    void insertAtHead(int d){
        Node* newnode = new Node(d);
        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
        length++;
    }

    void insertAtEnd(int d){
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
        length++;
    }

    void insert(int pos, int d){
        if(pos==1)
            insertAtHead(d);
        else if(pos>length+1)
            cout<<"You want to insert at position "<<pos<<"."<<" Not possible! There are only "<<length<<" elements in the list."<<endl;
        else if(pos<1)
            cout<<"You want to insert at position "<<pos<<"."<<" Are you serius bruh!?"<<endl;
        else{
            int c=1;
            Node* temp = head;
            while(c<pos-1){
                temp = temp->next;
                c++;
            }
            Node* newnode = new Node(d);

            if(temp->next == NULL)
                temp->next = newnode;
            else{
                newnode->next = temp->next;
                temp->next = newnode;
            }
            length++;
        }
    }

    void reverse(){
        if(head!=NULL || head->next == NULL){
            Node* p = NULL;
            Node* c = head;
            Node* f = head->next;

            while(f!=NULL){
                c->next = p;
                p = c;
                c = f;
                f = c->next;
            }
            c->next = p;
            head = c;
        }
    }
    void solve(Node* curr, Node* prev)
    {
        if(curr == NULL){
            head=prev;
            return ;
        }

        Node* f = curr->next;
        solve(f, curr);
        curr->next = prev;
    }

    void recursiveReverse(){
        Node* c = head;
        Node* p = NULL;
        solve(c, p);
    }

    Node* solve(Node* h){
        if(h==NULL || h->next == NULL)
            return h;
        
        Node* smallHead = solve(h->next);
        h->next->next = h;
        h->next = NULL;

        return smallHead;
    }

    void recursiveReverse2(){
        head = solve(head);
    }
};

int main(){
    SLL* l1 = new SLL();
    l1->insertAtEnd(10);    
    l1->insertAtEnd(20);
    l1->insertAtEnd(30);
    l1->insertAtEnd(40);
    l1->insertAtEnd(50);
    l1->insertAtEnd(60);
    l1->printList();
    l1->recursiveReverse2();
    l1->printList();
    l1->insertAtEnd(70);
    l1->printList();
    l1->insertAtHead(80);
    l1->printList();
    l1->insert(3, 25);
    l1->printList();

    return 0;
}

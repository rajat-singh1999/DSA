#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL{
    public:
    Node* head;
    int length;

    DLL(){
        head = NULL;
        length = 0;
    }

    void printList(){
        if(head!=NULL){
            Node* temp = head;
            while(temp!=NULL){
                cout<<"<-"<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
        else
            cout<<"Nothing to print!"<<endl;
    }

    void insertHead(int d){
        if(head == NULL){
            Node* newnode = new Node(d);
            head = newnode;
        }
        else{
            Node* newnode = new Node(d);
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
        length++;
    }

    void insertEnd(int d){
        if(head == NULL){
            Node* newnode = new Node(d);
            head = newnode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            Node* newnode = new Node(d);
            temp->next = newnode;
            newnode->prev = temp;
        }
        length++;
    }

    void insert(int pos, int d){
        if(pos>length+1)
            cout<<"Not possible, position of intertion is greater than length of list!"<<endl;
        else if(pos<1)
            cout<<"Not possible, position of intersion is less than 1!"<<endl;
        else if(pos == 1)
            insertHead(d);
        else if(pos == length+1)
            insertEnd(d);
        else {
            Node* temp = head;
            int c=1;
            while(c<pos-1){
                temp = temp->next;
                c++;
            }
            Node* newnode = new Node(d);
            if(temp->next == NULL){
                temp->next = newnode;
                newnode->prev = temp;
            }
            else{
                newnode->next = temp->next;
                temp->next = newnode;
                temp->next->prev = newnode;
                newnode->prev = temp;
            }
            length++;
        }
    }

    void removePos(int pos){
        if(head == NULL)
            cout<<"Nothing to remove!"<<endl;
        else if(pos==1){
            head = head->next;
            head->prev = NULL;
            length--;
        }
        else if(pos>length){
            cout<<"Not possible! The list has only "<<length<<" elements."<<endl;
        }
        else if(pos<1)
            cout<<"Not possible!"<<endl;
        else{
            Node* temp = head;
            int c=1;
            while(c<pos-1){
                temp = temp->next;
                c++;
            }
            Node* p = temp;
            p = p->next;
            if(p->next == NULL){
                temp->next = NULL;
                length--;
            }
            else{
                temp->next = p->next;
                p->next->prev = temp;
                length--;
            }

        }
    }

    void remove(int d){
        if(head != NULL){
            Node* p = head;
            if(p->data == d){
                head = head->next;
                length--;
                return ;
            }
            Node* temp = head;
            temp = head->next;
            while(temp!=NULL){
                if(temp->data == d){
                    p->next = temp->next;
                    temp = temp->next;
                    if(temp != NULL)
                        temp->prev = p;

                    length--;
                    return ;
                }
                p = p->next;
                temp = temp->next;
            }
            cout<<"Not found."<<endl;
        }
        else
            cout<<"Nothing to remove!"<<endl;
    }
};

int main(){
    DLL* l = new DLL();
    l->printList();
    l->insertHead(10);
    l->printList();
    l->insertEnd(11);
    l->printList();
    l->insert(3, 15);
    l->printList();
    l->insert(2, 16);
    l->printList();
    l->insert(4, 23);
    l->printList();
    l->removePos(5);
    l->printList();
    l->remove(11);
    l->printList();
    l->remove(16);
    l->printList();


    return 0;
}
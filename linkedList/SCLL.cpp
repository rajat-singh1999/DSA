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

class SCLL{
    public:
    Node* tail;
    int length;

    SCLL(){
        this->tail = NULL;
        this->length = 0;
    }

    void insertPos(int pos, int d){
        Node* head = tail;
        if(head!=NULL){
            head = head->next;
            if(pos==1){
                Node* newnode = new Node(d);
                newnode->next = head;
                tail->next = newnode;
                length++;
            }
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

                if(temp->next == head){
                    temp->next = newnode;
                    newnode->next = head;
                    tail = newnode;
                }
                else{
                    newnode->next = temp->next;
                    temp->next = newnode;
                }
                length++;
            }
        }
        else{
            Node* newnode = new Node(d);
            newnode->next = newnode;
            head = newnode;
            tail=head;
            length++;
        }
    }

    void removeAtPos(int pos){
        Node* head = tail;
        if(head != NULL){
            head = head->next;
            if(pos == 1 && length!=1){
                head = head->next;
                tail->next = head;
                length--;
            }
            else if(pos == 1 && length==1){
                tail = NULL;
                length--;
            }
            else if(pos>length)
                cout<<"You want to remove at position "<<pos<<"."<<" Not possible! There are only "<<length<<" elements in the list."<<endl;
            else if(pos<1)
                cout<<"You want to remove at position "<<pos<<"."<<" Are you serius bruh!?"<<endl;
            else{
                Node* temp = head;
                int c = 1;
                while(c<pos-1){
                    temp=temp->next;
                    c++;
                }
                if(temp->next == tail){
                    temp->next = head;
                    tail = temp;
                }
                else
                    temp->next = temp->next->next;
                length--;
            }
        }
        else
            cout<<"Nothing to remove!"<<endl;
    }

    void remove(int data){
        Node* head = tail;
        if(head != NULL){
            head = head->next;
            if(data == head->data){
                tail->next = head->next;
            }
            else{
                Node* temp = head;
                Node* p = temp->next;
                while(p != tail){
                    if(p->data == data){
                       temp->next = p->next;
                       length--;
                       cout<<"yes"<<endl;
                       return ; 
                    }
                    temp = temp->next;
                    p = p->next;
                }
                if(p->data == data){
                    tail = temp;
                    tail->next = head;
                    length--;
                    return ;
                }
                cout<<"Not found!"<<endl;
            }
        }
        else
            cout<<"Nothing to remove!"<<endl;
    }


    void printList(){
        if(tail == NULL)
            cout<<"Empty list!"<<endl;
        else{
            Node* temp = tail;
            do{
                temp = temp->next;
                cout<<temp->data<<" ";
            }while(temp!=tail);
            cout<<endl;
        }
    }
};

int main(){
    SCLL* l = new SCLL();

    l->insertPos(1, 25);
    l->printList();
    l->insertPos(2, 35);
    l->printList();
    l->insertPos(2, 45);
    l->printList();
    l->insertPos(l->length+1, 55);
    l->printList();
    l->insertPos(1, 65);
    l->printList();
    l->insertPos(4, 75);
    l->printList();
    l->remove(55);
    l->printList();
    l->remove(35);
    l->printList();
    return 0;
}
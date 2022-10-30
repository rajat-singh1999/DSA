#include<iostream>
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

class DCLL {
    public:
    Node* head;
    int length;

    DCLL(){
        head = NULL;
        length = 0;
    }

    void printList(){
        if(head != NULL){
            Node* tail = head->prev;
            Node* temp = tail;
            do{
                temp = temp->next;
                cout<<temp->data<<" ";
            }while(temp!=tail);
            cout<<endl;
            
        }
        else
            cout<<"Empty list. Nothing to print!"<<endl;
    }
    
    void insert(int pos, int d){
        if(head == NULL){
            Node* newnode = new Node(d);
            newnode->next = newnode;
            newnode->prev = newnode;
            head = newnode;
            length++;
        }
        else{
            if(length == 1 && pos == 1){
                Node* newnode = new Node(d);
                newnode->next = head;
                newnode->prev = head;
                head = newnode;
                length++;
            }
            else if(pos>length+1)
                cout<<"Not possible"<<endl;
            else if(pos<1)
                cout<<"Not possible"<<endl;            
            else if(pos == 1){
                Node* newnode = new Node(d);
                newnode->next = head;
                newnode->prev = head->prev;
                head->prev->next = newnode;
                head = head->next;
                head->prev = newnode;
                head = newnode;
                length++;
            }
            else{
                Node* temp = head;
                int c=1;
                while(c<pos-1){
                    temp = temp->next;
                    c++;
                }
                Node* newnode = new Node(d);
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next->prev = newnode;
                temp->next = newnode;
                length++;
            }
        }
        printList();
    }

    void removeAtPos(int pos){
        if(head!=NULL){
            if(pos>length || pos<1)
                cout<<"Not possible"<<endl;
            else if(pos==1){
                if(length==1)
                    head=NULL;
                else{
                    Node* tail = head->prev;
                    head = head->next;
                    head->prev = tail;
                    tail->next=head;
                    length--;
                }
            }
            else{
                Node* temp = head->prev;
                Node* p = head;
                int c=1;
                while(c<pos){
                    temp = temp->next;
                    p=p->next;
                    c++;
                }
//                cout<<endl<<temp->data<<" "<<p->data<<endl;
                temp->next = p->next;
                p->next->prev = temp;
                length--;
            }
        }
        else
            cout<<"Nothing to remove."<<endl;
        printList();
    }

    void remove(int d){
        if(head == NULL)
            cout<<"Nothing to remove"<<endl;
        else{
            if(head->data == d){
                if(length == 1){
                    head=NULL;
                    length--;
                    printList();
                    return ;
                }
                Node* tail = head->prev;
                head = head->next;
                head->prev = tail;
                tail->next = head;
                length--;
            }
            else{
                Node* p =head;
                Node* temp = p->next;
                while(temp->next!=head){
                    if(temp->data == d){
                        p->next = temp->next;
                        temp->next->prev = p;
                        length--;
                        printList();
                        return ;
                    }
                    temp = temp->next;
                    p=p->next;
                }
                if(temp->data == d){
                    p->next = head;
                    head->prev = p;
                    length--;
                }
                else
                    cout<<"Not found!"<<endl;
            }
            printList();
        }
    }

};

int main(){
    DCLL* l = new DCLL();
    l->insert(1,10);
    l->insert(2, 20);
    l->insert(3, 30);
    l->insert(4,40);
    l->insert(5,50);
    l->insert(6, 60);

    l->remove(10);
    l->remove(60);
    l->remove(30);
    l->remove(20);
    l->remove(50);
    l->remove(40);
    l->remove(1);
/*
*/
    return 0;
}
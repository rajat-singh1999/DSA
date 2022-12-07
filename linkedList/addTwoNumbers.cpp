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

    void removeAtPos(int pos){
        if(head != NULL){
            if(pos == 1){
                head = head->next;
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
                Node* p = temp;
                p = p->next;
                temp->next = p->next;
                length--;
            }
        }
        else
            cout<<"Nothing to remove!"<<endl;
    }

    void remove(int d){
        if(head != NULL){
            Node* prev = head;
            if(prev->data == d){
                head = head->next;
                length--;
                return ;
            }
            Node* temp = head;
            temp = head->next;
            while(temp!=NULL){
                if(temp->data == d){
                    prev->next = temp->next;
                    length--;
                    return ;
                }
                prev = prev->next;
                temp = temp->next;
            }
            cout<<"Not found."<<endl;
        }
        else
            cout<<"Nothing to remove!"<<endl;
    }

    int getNum(){
        if(head == NULL){
            return -1;
        }
        else{
            int ans=0;
            Node* temp = head;
            while(temp!=NULL){
                ans*=10;
                ans+=temp->data;
                temp = temp->next;
            }
            return ans;
        }
    }

};

int main(){
    SLL* num1 = new SLL();
    num1->insertAtEnd(2);
    num1->insertAtEnd(1);
    num1->insertAtEnd(3);

    SLL* num2 = new SLL();
    num2->insertAtEnd(3);
    num2->insertAtEnd(4);
    num2->insertAtEnd(5);

    int n1 = num1->getNum();
    int n2 = num2->getNum();
    cout<<"the numbers are: "<<n1<<" "<<n2<<endl;

    int sum = n1+n2;
    SLL* ans = new SLL();
    while(sum!=0){
        int d = sum%10;
        ans->insertAtHead(d);
        sum/=10;
    }

    ans->printList();
    return 0;
}
#include<iostream>
#include<String>
#include  <bits/stdc++.h>

using namespace std;

class Stack {
    //properties
    public:
        char *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new char[size];
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    char pop() {
        if(top >=0 ) {
            return arr[top--];
        }
        else{
            cout << "Stack UnderFlow" << endl;
            return -1;
        }
    }

    char peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    string s = "";
    cout<<"Input String: ";
    getline(cin, s);

    int n = s.length();
    Stack st(n);

    for(int i=0; i<n; i++){
        st.push(s[i]);
    }

    string ans = "";

    for(int i=0; i<n; i++){
        ans.append(1, st.pop());
    }
    cout<<endl<<"Answer: "<<ans<<endl;
    return 0;
}
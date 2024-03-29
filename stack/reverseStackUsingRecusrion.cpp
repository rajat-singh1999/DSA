#include<iostream>
using namespace std;

class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
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

    void pop() {
        if(top >=0 ) {
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
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
    
    void print(){
        cout<<"h1"<<top<<endl;
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<"h2"<<endl;
    }

};


void solve1(Stack &inputStack, int val, int size) {
    //base case
    if(inputStack.isEmpty()) {
        inputStack.push(val);
        return ;
    }
    
    int num = inputStack.peek();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve1(inputStack, val, size);
    
    inputStack.push(num);
    
}

void solve(Stack &inputStack, int size) {
    //base case
    if(inputStack.isEmpty()) {
        return ;
    }
    
    int num = inputStack.peek();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack, size);
    
    solve1(inputStack, num, size);
    
}

int main(){
    int N = 7;
	Stack inputStack(N);

    inputStack.push(7);
    inputStack.push(4);
    inputStack.push(2);
    inputStack.push(78);
    inputStack.push(41);
    
    inputStack.print();

    solve(inputStack, N-1);
    
    inputStack.print();
    return 0;
}
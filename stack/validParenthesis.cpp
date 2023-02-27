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
            
        }
    }

    char pop() {
        if(top >=0 ) {
            return arr[top--];
        }
        else{
            
            return -1;
        }
    }

    char peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            
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

bool isValidParenthesis(string expression)
{
  	 Stack s(expression.length());
     for(int i=0; i<expression.length(); i++) {
         
         char ch = expression[i];
         
         //if opening bracket, stack push
         //if close bracket, stacktop check and pop
         
         if(ch == '(' || ch == '{' || ch == '['){
             s.push(ch);
         }
         else
         {
             //for closing bracket
             if(!s.isEmpty()) {
                  char top = s.peek();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      s.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             else
             {
                 return false;
             } 
         }  
     }
    
    if(s.isEmpty())
        return true;
    else
        return false;
}

int main(){
    string s = "[()]{}()()])}";
    cout<<isValidParenthesis(s)<<endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

char stack[1];
int top=-1,n=1;

void push(char a) {
    top++;
    stack[0]=a;
}

void pop(){
    top--;
}

int main(){
    
    //char str[16];
    string str;

    cout<<"Enter the 15 bits : "<<endl;
    getline(cin, str);

    if(str.length()!=15){
        cout<<"Invalid Input!"<<endl;
        return 0;
    }

    else{
        for(int i=0; i<15;i++){
            if(str[i]=='1'){
                if(top==-1)
                    push('1');
                else
                    pop();
            }
            else if(str[i]=='0')
                continue;
            else{
                cout<<"Invalid Input!"<<endl;
                return 0;
            }   
        }

        if(top==-1){
            cout<<"The parity is even : "<<endl;
            str=str+'0';
            cout<<str;
        }
        else{
            cout<<"The parity is odd : "<<endl;
            str=str+'1';
            cout<<str;
            }
    }
    return 0;
}

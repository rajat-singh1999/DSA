/*
Develop a program to find the parity is EVEN PARITY or ODD PARITY of the given
ERROR DETECTION CODE given as the input string. The given input string contains
only the binary digits (bits) either 0 or 1. Assume the input string is of the
half word length i.e., 16 bits and the last bit is allocated to assign the parity.
The parity bit ZERO i.e., 0 represents EVEN PARITY and the parity bit ONE i.e., 1 represents ODD PARITY.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    if(str.length()==16){
        if(str[15]=='0')
            cout<<"ERROR DETECTION CODE HAS EVEN PARITY."<<endl;
        else
            cout<<"ERROR DETECTION CODE HAS ODD PARITY."<<endl;
    }
    else
        cout<<"EROOR DETECTION CODE is either incomplete or incorrect. It should have exactly 16 bits."<<endl;
    return 0;
}

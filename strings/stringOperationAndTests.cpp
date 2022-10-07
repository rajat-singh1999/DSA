#include<bits/stdc++.h>
using namespace std;

int lengthOf(char a[]){
    int c=0;
    for(int i=0;a[i]!='\0';i++)
        c++;
    return c;
}

void reverse(char name[], int n){
    int s=0;
    int e=n-1;

    while(s<=e)
        swap(name[s++], name[e--]);
}

char toUPPERCase(char ch){
    if((ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        return ch;
    else
        return (ch - 'a' + 'A');
}

bool checkIfAlphaOrNum(char ch){
    if((ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        return 1;
    return 0;
}

int main(){
    char name[20];
    cout<<"Enter a name: ";
    cin>>name;
    int l = lengthOf(name);
    cout<<"Length of the name you entered is "<<l<<"."<<endl;
    reverse(name, l);
    cout<<"Reverse of the string you entered:  "<<name<<"."<<endl<<endl;

    cout<<toUPPERCase(name[0])<<endl;
    cout<<checkIfAlphaOrNum(name[0])<<endl;
    cout<<checkIfAlphaOrNum(toUPPERCase(name[0]))<<endl;
    return 0;
}
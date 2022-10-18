#include<iostream>
#include<string>
using namespace std;

void reverse(int i, string& s){
    int j = s.length()-i-1;
    if(i>j)
        return ;
    swap(s[i], s[j]);
    i++;
    reverse(i, s);
}

int main(){
    string str;
    getline(cin, str);
    reverse(0, str);
    cout<<endl<<str.length()<<endl;
    cout<<endl<<"The reversed string is "<<str<<"."<<endl;
}
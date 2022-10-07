#include<bits/stdc++.h>
using namespace std;

string removeDuplicate(string &s)
{
    // Write your code here
    int n=s.length();
    int i=0,m=n-1;
    while(i<m){
        if(s[i]==s[i+1]){
            s.erase(i,2);
            m=m-2;
            if(i!=0)
                i--;
        }
        else
            i++;
    }
    return s;
}

int main(){
    string str;
    getline (cin, str);
    str=removeDuplicate(str);
    cout<<str<<endl;
    return 0;
}

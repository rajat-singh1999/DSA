#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
}

int main(){
    string str;
    getline (cin, str);
    string part;
    getline(cin, part);
    cout<<endl<<removeOccurrences(str, part)<<endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(int i, string s){
    int j = s.length()-i-1;
    if(s[i]!=s[j])
        return false;
    else if(i>j)
        return true;
    else
        return checkPalindrome(++i, s);
}

int main(){
    string str;
    getline(cin, str);
    bool ans = checkPalindrome(0, str);
    cout<<endl<<ans<<"."<<endl;
    return 0;
}
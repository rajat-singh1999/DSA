#include<bits/stdc++.h>
using namespace std;

char getMaxOccCharacter(string s){
    int arr[26] = {0};

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        int num=0;
        if(ch>='a' && ch<='z'){
            num=ch -'a';
        }
        else{
            num=ch-'A';
        }
        arr[num]++;
    }
    int maxi=-1,ans=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }

    char finalAns = 'a'+ans;
    return finalAns;
}

int main(){
    string s;
    cin>>s;
    cout<<endl<<getMaxOccCharacter(s)<<endl;
    return 0;
}


/*
Given a string str.
The task is to find the maximum occurring character in the string str.
If more than one character occurs the maximum number of time then print the lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.
Example 2:

Input:
str = output
Output: t
Explanation:  t and u are the characters
with the same frequency, but t is
lexicographically smaller.
*/
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.


*/

#include<bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26], int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i])
            return 0;
    }    
    return 1;
}

bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
    
    for(int i=0;i<s1.length();i++){
        count1[s1[i]-'a']++;
    }
    
    int i=0;
    int count2[26]={0};
    int windowSize=s1.length();
    
    while(i<windowSize && i<s2.length()){
        count2[s2[i]-'a']++;
        i++;
    }
    if(checkEqual(count1, count2))
        return 1;
    
    while(i<s2.length()){
        char newChar=s2[i];
        int index=newChar-'a';
        count2[index]++;
        
        char oldChar = s2[i-windowSize];
        index = oldChar-'a';
        count2[index]--; //removing the count of old character
        i++;
        
        if(checkEqual(count1,count2))
            return 1;
    }
    return 0;
}

int main(){
    string subStr;
    getline (cin, subStr);
    string str;
    getline(cin, str);
    cout<<endl<<checkInclusion(subStr, str)<<endl;
    return 0;
}
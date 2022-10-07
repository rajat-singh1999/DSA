#include<bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
    // Write your code here.
   str+=' ';
   vector<string> v;
   string temp="";
   for(int i=0;i<str.size();i++){
       if(str[i]==' ') {
           if(temp.length())
               v.push_back(temp);
           temp="";
         }
       else 
           temp+=str[i];
          }
   reverse(v.begin(),v.end());
   string ans="";
   for(int i=0;i<v.size();i++){
       ans+=v[i];
       ans+=' ';
   }
   ans.pop_back();
   return ans;
}

int main(){
    string str = "My name is Rajat Singh!";
    str = reverseString(str);
    cout<<str<<endl;
    return 0;
}
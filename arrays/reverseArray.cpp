#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    int n=arr.size();
    int start=m+1;
    int end=n-1;
    
    while(start<=end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    vector<int> v = {4, 8, 17, 12, 37, 24, 69};
    int m=2;
    reverseArray(v, m);
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<" "<<v.at(i);
    }
    cout<<endl;
}

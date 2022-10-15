#include <bits/stdc++.h> 
using namespace std;

int firstOcc(vector<int>& arr, int ans, int k, int s, int e){
    int mid=(s+((e-s)/2));
    if(s>e)
        return ans;
    if(arr[mid]==k){
        ans=mid;
        e=mid-1;
    }
    else if(k>arr[mid])
        s=mid+1;
    else
        e=mid-1;
    return firstOcc(arr, ans, k, s, e);
}

int lastOcc(vector<int>& arr, int ans, int k, int s, int e){
    int mid=(s+((e-s)/2));
    if(s>e)
        return ans;
    if(arr[mid]==k){
        ans=mid;
        s=mid+1;
    }
    else if(k>arr[mid])
        s=mid+1;
    else
        e=mid-1;
    return lastOcc(arr, ans, k, s, e);
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr, -1, k, 0, n-1);
    p.second = lastOcc(arr, -1, k, 0, n-1);
    
    return p;
}

int main(){
    vector<int> arr = {1,2,3,3,3,3,3,4,7};
    int n=9;
    int k=69;
    pair<int,int> ans = firstAndLastPosition(arr, n, k);
    cout<<ans.first<<" and "<<ans.second<<endl;
    return 0;
}   
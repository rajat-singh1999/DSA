#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start=0, end=arr.size()-1;
    int mid = start+((end-start)/2);
    
    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start=mid+1;
        }
        else
            end=mid;
        mid = start+((end-start)/2);
    }
    return start;
}

int main(){
    vector<int> arr = {0,2,5,10,2};
    int n=9;
    int k=3;
    int ans = peakIndexInMountainArray(arr);
    cout<<ans<<endl;
    return 0;
}
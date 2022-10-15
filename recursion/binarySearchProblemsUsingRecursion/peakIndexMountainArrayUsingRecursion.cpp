#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr, int s, int e, int mid){
    if(s>=e)
        return mid;
    else if(arr[mid]<arr[mid+1])
            s=mid+1;
    else
        e=mid;

    mid=(s+((e-s)/2));
    return peakIndexInMountainArray(arr, s, e, mid);

}

int main(){
    vector<int> arr = {0,2,5,10,2};
    int s=0;
    int e=arr.size()-1;
    int ans = peakIndexInMountainArray(arr, s, e, (s+((e-s)/2)));
    cout<<ans<<endl;
    return 0;
}
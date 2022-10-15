#include<iostream>
using namespace std;

int binSearch(int *arr, int k, int s, int e){
    int mid=(s+((e-s)/2));
    if(s>e)
        return -1;

    else if(arr[mid]==k)
        return mid;
    
    else if(arr[mid]<k)
        s=mid+1;

    else
        e=mid-1;

    return binSearch(arr, k, s, e);
}

int main(){
    int arr[] = {2,6,14,33,41,66};
    int n = 6;
    int k = 2;
    int s=0;
    int e=n-1;
    int mid = (s+((e-s)/2));
    int ans = binSearch(arr, k, s, e);
    cout<<endl<<ans<<endl;
    return 0;
}
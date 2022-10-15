#include<bits/stdc++.h>
using namespace std;

int pivotIndex(int *arr, int s, int e, int mid){
    if(s>=e)
        return mid;
    else if(arr[mid] >= arr[0])
            s=mid+1;
    else
        e=mid;

    mid=(s+((e-s)/2));
    return pivotIndex(arr, s, e, mid);

}

int main(){
    int arr[7] = {9,10,17,1,3,7,8};
    int n=7;
    int s=0,e=n-1;
    int mid = s+((e-s)/2);
    cout<<"Pivot is "<<pivotIndex(arr, s, e, mid)<<endl;
    return 0;
}
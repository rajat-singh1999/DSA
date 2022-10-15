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

int findPosition(int *arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int s=0, e=n;
    int mid = s+((e-s)/2);
    int pivot = pivotIndex(arr, s, e, mid);
    int ans = -1;
    
    if(k>=arr[pivot] && k<=arr[n-1])
        ans = binSearch(arr, k, pivot, n-1);

    else
        ans = binSearch(arr, k, 0, pivot-1);
    
    return ans;
}

int main(){
    int arr[] = {10,17,1,3,8};
    cout<<"The index is "<< findPosition(arr, 5, 17);
    return 0;
}
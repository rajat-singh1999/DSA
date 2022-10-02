#include <bits/stdc++.h> 
using namespace std;

int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getPivot(arr, n);
    int ans = -1;
    
    if(k>=arr[pivot] && k<=arr[n-1])
        ans = binarySearch(arr, pivot, n-1, k);

    else
        ans = binarySearch(arr, 0, pivot-1, k);
    
    return ans;
}

int main(){
    vector<int> arr = {10,17,1,3,8};
    cout<<"The index is "<< findPosition(arr, 5, 18);
    return 0;
}
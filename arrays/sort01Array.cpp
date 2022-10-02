#include <bits/stdc++.h>
using namespace std;

void sort01(int *arr, int n)
{
   //   Write your code here
    int i=0,j=n-1;
    while(i<j){
        while(arr[i]==0 && i<j)
            i++;

        while(arr[j]==1 && i<j)
            j--;
        
        if(arr[i]==1 && arr[j]==0 && i<j){
            int temp=arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10] = {1,1,0,0,1,1,1,0,0,1};
    int n = 10;
    sort01(arr, n);
    return 0;
}
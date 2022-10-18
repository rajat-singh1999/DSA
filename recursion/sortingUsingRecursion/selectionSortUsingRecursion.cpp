#include<iostream>
using namespace std;

void sortArray(int *arr, int n){
    if(n==0)
        return ;
    
    int maxi = n-1;
    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1])
            maxi = i-1;
    }
    swap(arr[n-1], arr[maxi]);
    sortArray(arr, n-1);
}

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[5] = {5,4,3,2,1};
    printArray(arr,5);
    sortArray(arr, 5);
    printArray(arr, 5);
    return 0;
}

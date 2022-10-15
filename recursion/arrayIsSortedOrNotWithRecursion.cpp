#include<iostream>
using namespace std;

bool isSorted(int *arr, int size){
    if(size==0 || size==1)
        return true;
    
    if(arr[0]>arr[1])
        return false;
    
    return isSorted(arr+1, size-1);
}

int main(){
    int arr[] = {24, 37, 144, 56, 73, 149};
    if(isSorted(arr, 6))
        cout<<endl<<"Sorted"<<endl;
    else
        cout<<endl<<"Not Sorted"<<endl;
    return 0;
}
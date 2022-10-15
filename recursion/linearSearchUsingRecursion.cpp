#include<iostream>
using namespace std;

//best way
bool linSearch(int *arr, int k, int size){
    if(size==1 && arr[0]!=k)
        return false;
    if(arr[0]==k)
        return true;
    return linSearch(arr+1, k, size-1);
}

//using an iterated from back to front
int linSearch2(int *arr, int n, int k){
    if(n==0)
        return -1;
    if(arr[n-1]==k)
        return n-1;

    return linSearch2(arr, n-1, k);
}

//using an iterator from front to back
int linSearch3(int *arr, int size, int k, int i=0){
    if(i==size)
        return -1;
    if(arr[i]==k)
        return i;
    return linSearch3(arr, size, k, i+1);
}

int main(){
    int arr[] = {4,17,11,2,15,6};
    int size = 6;
    int k = 6;
    if(linSearch(arr, k, size))
        cout<<endl<<k<<" is present in the array!"<<endl;
    else
        cout<<endl<<k<<" is not present in the array!"<<endl;

    int ansIndex = linSearch2(arr,size,k);
    cout<<endl<<ansIndex<<endl;

    ansIndex = linSearch3(arr, size, k);
    cout<<endl<<ansIndex<<endl;

    return 0;
}
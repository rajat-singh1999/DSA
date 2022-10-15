#include<iostream>
using namespace std;

//back to front approach
int sum(int *arr, int n){
    if(n==0)
        return 0;
    return arr[n-1] + sum(arr, n-1);
}

//front to back traditional approach
int sum2(int *arr, int n){
    if(n==0)
        return 0;
    return arr[0] + sum(arr+1,n-1);
}

int main(){
    int arr[] = {2,3,7,11};
    cout<<endl<<sum(arr, 4);
    cout<<endl<<sum2(arr, 4);
    return 0;
}
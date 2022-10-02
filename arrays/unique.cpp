#include<iostream>
using namespace std;

int freq(int arr[], int x, int n){
    int f=0;
    for(int i=0;i<n;i++){
        if(arr[i] == x)
            f++;
    }
    return f;
}
int main(){
    int arr[6] = {1,2,7,2,7,2};
    int n=sizeof(arr)/sizeof(arr[0]), cur=0;

    for(int i=0;i<n;i++){
        int temp = freq(arr, arr[i], n);
    }
    return 0;
}
//incomplete
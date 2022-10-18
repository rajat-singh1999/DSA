#include<iostream>
using namespace std;

void sortArray(int *arr, int n, int i=1){
    if(i==n)
        return ;
    
    int temp = arr[i];
    int j = i-1;
    for(; j>=0; j--) {
        if(arr[j] > temp) {
            //shift
            arr[j+1] = arr[j];
        }
        else { // ruk jao
            sortArray(arr, n, ++i);
        }
    }
    //copy temp value
    arr[j+1] = temp;
    sortArray(arr, n, ++i);
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

#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
}

int main(){
    vector<int> arr = {26,12,37,15,77,69};
    insertionSort(arr, arr.size());
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    return 0;
}
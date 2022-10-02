#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    vector<int> arr = {26,12,37,15,77,69};
    selectionSort(arr, arr.size());
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    return 0;
}
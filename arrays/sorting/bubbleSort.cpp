#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}

int main(){
    vector<int> arr = {26,12,37,15,77,69};
    bubbleSort(arr, arr.size());
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    return 0;
}
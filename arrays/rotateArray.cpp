#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
      
      int n = nums.size();
      vector<int> temp(n);

      for(int i =0;i<n;i++)
        temp[(i+k)%n] = nums[i];
      
      for(int i=0;i<nums.size();i++)
        nums[i] = temp[i];
}
void print(vector<int>& arr){
    cout<<"Look->";
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k=2;
    rotate(arr, k);
    print(arr);
    return 0;
}
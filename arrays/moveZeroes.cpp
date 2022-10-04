#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i=0;
    for(int j=0;j<nums.size();j++){
        if(nums[j]!=0){
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main(){
    vector<int> v = {0,1,0,3,12,0};
    moveZeroes(v);
    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
    return 0;
}
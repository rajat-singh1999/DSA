#include <bits/stdc++.h>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i=0,j=0;
    
    while(i<n && j<m) {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;// Write your code here.
}
 int main(){
    vector<int> arr1 = {1,2,2,2,3,4};
    vector<int> arr2 = {2,2,3,3};
    int n=6,m=4;
    vector<int> temp = findArrayIntersection(arr1,n,arr2,m);
    cout<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    return 0;
 }
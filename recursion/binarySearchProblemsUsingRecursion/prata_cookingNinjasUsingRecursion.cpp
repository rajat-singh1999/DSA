#include<bits/stdc++.h>
using namespace std;

int isValid(vector<int> arr, int n, int m, int mid){
    int dishesCount = 0;
   int timeSum = 0;
   for(int i=0; i<n; i++){
       for(int j=1; j<=m; j++){
           timeSum += arr[i]*j;
           if(timeSum <= mid){
               dishesCount++;
               if(dishesCount == m){
                   return true;
               }
           }
       }
       timeSum = 0;
   }
   return false;
}

int cooking_paratha(vector<int> arr, int s, int e, int m, int ans){
    int mid = s+((e-s)/2);
    if(s>e)
        return ans;
    else if(isValid(arr, arr.size(), m, mid)){
        ans=mid;
        e=mid-1;
    }
    else
        s=mid+1;
    return cooking_paratha(arr, s, e, m, ans);
}

int main(){
    vector<int> arr = {1,2,3,4};
    int n=arr.size();
    int m = 11;

    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    int s=0,e=maxi*m;
    int mid = s+((e-s)/2);
    int ans=-1;
    
    cout<<cooking_paratha(arr, s, e, m, ans)<<endl<<endl;
    cout<<isValid(arr, n, m,13)<<endl;
    return 0;
}

/*
https://bit.ly/3ExHXt5


IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

Example
Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
12
36
1
*/
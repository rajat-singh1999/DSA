#include<bits/stdc++.h>
using namespace std;

int giveSum(vector<int> arr, int n, int mid){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid)
            sum+=(arr[i]-mid);
    }
    return sum;
}

int eko(vector<int> arr, int s, int e, int k){
    int mid=s+((e-s)/2);
    if(s>e)
        return -1;
    if(giveSum(arr,arr.size(),mid)==k)
        return mid;
    else if(giveSum(arr, arr.size(), mid)>k)
        s=mid+1;
    else
        e=mid-1;
    return eko(arr, s, e, k);
}

int main(){
    vector<int> arr = {4,42,40,26,46};
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i]);
    }
    int target = 20;
    int s=0,e=maxi;

    cout<<"Answer= "<<eko(arr, s, e, target)<<endl;
    //cout<<giveSum(arr, n, 10)<<endl;
    return 0;
}

/*
Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

Output
The first and only line of output must contain the required height setting.

Example

Input:
4 7
20 15 10 17

Output:
15


Input:
5 20
4 42 40 26 46

Output:
36
*/

/*
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&leftPanelTab=0
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &a, vector<int> &dp){
    if(i == 0) return 0;
    if(dp[i]!=-1) return dp[i];
    int left = f(i-1, a, dp) + abs(a[i] - a[i-1]);
    int right = INT_MAX;
    if(i>1) right = f(i-2, a, dp) + abs(a[i]-a[i-2]);

    dp[i] = min(left, right);
    return dp[i];
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, -1);
    return f(n-1, heights, dp);
}
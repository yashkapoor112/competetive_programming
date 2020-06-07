/*
Source code by Yash Kapoor
Problem Statement - Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.
Problem Link - https://leetcode.com/problems/maximum-subarray/
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int max_subarray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n+1,0);

    int fin_max = INT_MIN;
    int currmax,prevmax;
    currmax=prevmax=0;
    
    for (int i = 0; i < n; ++i)
    {
        dp[i+1] = nums[i];
        dp[i+1] = max(dp[i+1], dp[i]+nums[i]);
        fin_max = max(dp[i+1], fin_max);
        dp[i] = dp[i+1];      
    }
    return fin_max;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n,0);
        int value;
        for (int i = 0; i < n; ++i)
        {
            cin >> value;
            nums.pb(value);
        }
        cout << max_subarray(nums) << endl;
    }
}
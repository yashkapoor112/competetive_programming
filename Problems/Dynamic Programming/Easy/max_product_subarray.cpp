/*
Source code by Yash Kapoor
Problem Statement - 
Problem Link - 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int max_subarray(vector<int> &nums)
{
    int n = nums.size();

    int fin_max = INT_MIN;
    int min_prod,max_prod;
    min_prod=max_prod=nums[0];
    
    for (int i = 1; i < n; ++i)
    {
    	max_prod = max(max_prod, max(max_prod*nums[i], nums[i]));
    	min_prod = min(max_prod, min(min_prod*nums[i], nums[i]));
    	fin_max = max(fin_max, max_prod);
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
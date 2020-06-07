/*
Source code by Yash Kapoor
Problem Statement - 
Problem Link - https://leetcode.com/problems/paint-house-iii/
*/

class Solution {
public:
    int dp[101][101][21];
    int helper(int i, int t, int l, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(t > target)  return INT_MAX/2;
        if(i == m){
            if(t == target) return 0;
            else    return INT_MAX/2;
        }
        if(dp[i][t][l]!=-1)
            return dp[i][t][l];
        else{
            int ans = INT_MAX/2;
            if(houses[i] != 0)
                ans = min(ans, helper(i+1, l==houses[i]?t:t+1, houses[i], houses, cost, m, n, target));
            else
                for(int j = 0; j < n; j++)
                    ans = min(ans, cost[i][j] + helper(i+1, l==j+1?t:t+1, j+1, houses, cost, m, n, target));
            return dp[i][t][l] = ans;
        }    
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, 0, 0, houses, cost, m, n, target);
        return ans==INT_MAX/2?-1:ans;
    }
};
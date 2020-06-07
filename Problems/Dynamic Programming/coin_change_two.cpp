/*
Source code by Yash Kapoor
Problem Statement - 
Problem Link - https://leetcode.com/problems/coin-change-2/
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int col = coins.size(), row = amount;
        vector<vector<int> > dp(row+1, vector<int>(col+1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(i == 0)  dp[i][j] = 1;
                if(coins[j-1] > i)  dp[i][j] = dp[i][j-1];
                else    dp[i][j] = (dp[i-coins[j-1]][j]) + dp[i][j-1];
            }
        }
        return dp[amount][col];
    }
};
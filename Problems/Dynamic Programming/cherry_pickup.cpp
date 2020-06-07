/*
Source code by Yash Kapoor

Codeforces		yk112
Leetcode		yk112
Codechef		yashkapoor112

Problem Statement - 
Problem Link - https://leetcode.com/problems/cherry-pickup-ii/

*/
class Solution {
public:
    int directions[3] = {-1, 0, 1};
    int dp[70][70][70];
    int dfs(int r, int c1, int c2, int nor, int noc, vector<vector<int>>& grid)
    {
        if(r == nor || c1 == noc || c2 == noc || c1 == -1 || c2 == -1)  return 0;
        if(dp[r][c1][c2] != -1)     return dp[r][c1][c2];
        
        int temp, ans = 0;
        if(c1 == c2)    temp = grid[r][c1];
        else    temp = grid[r][c1] + grid[r][c2];
        
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                ans = max(ans, dfs(r+1, c1+directions[i], c2+directions[j], nor, noc, grid));
        
        return dp[r][c1][c2] = ans+temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, grid[0].size()-1, grid.size(), grid[0].size(), grid);
    }
};
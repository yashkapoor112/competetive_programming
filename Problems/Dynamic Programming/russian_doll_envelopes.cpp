/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - You have a number of envelopes with widths and heights given 
as a pair of integers (w, h). One envelope can fit into another if and only if 
both the width and height of one envelope is greater than the width and height
of the other envelope.

Problem Link - https://leetcode.com/problems/russian-doll-envelopes/

*/
class Solution {
public:
    int dp[10000];
    int vis[10000];
    static int compare(vector<int> a, vector<int> b){
        return a[0]==b[0]?a[1]>b[1]:a[0]>b[0];
    }
    int helper(int wide, int high, vector<vector<int>>& envelopes, int idx){
        if(dp[idx] != -1)   return dp[idx];
        else{
            int ans = 0;
            for(int k = 0; k < envelopes.size(); k++)
                if(wide < envelopes[k][0] && high < envelopes[k][1])
                    ans = max(ans, 1 + helper(envelopes[k][0], envelopes[k][1], envelopes, k));
            return dp[idx] = ans;
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(!envelopes.size())   return 0;
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        sort(envelopes.begin(), envelopes.end(), compare);
        for(int i = 0; i < envelopes.size(); i++)
            if(dp[i]!=-1)   ans = max(ans, dp[i]);
            else    ans = max(ans, 1+helper(envelopes[i][0], envelopes[i][1], envelopes, i));
        return ans;
    }
};
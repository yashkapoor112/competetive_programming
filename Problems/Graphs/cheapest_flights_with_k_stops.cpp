/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - 

Problem Link - https://leetcode.com/problems/cheapest-flights-within-k-stops/

This example is for DFS with pruning.
Note - Memoization also gives a tle here but pruning does not.
*/

class Solution {
public:
    #define pb push_back
    #define mp make_pair
    #define pii pair<int, int>
    void dfs(int src, int dst, int k, int cost, int &anss, vector<vector<pii> > &adjM, vector<int> &vis){
        if(src == dst){ anss = cost;return; }
        if(k == 0)  return;
        
        for(auto ad: adjM[src]){
            if(!vis[ad.first]){       
                if(cost + ad.second > anss)     continue; //pruning
                vis[ad.first] = 1;
                dfs(ad.first, dst, k-1, cost+ad.second, anss, adjM, vis);
                vis[ad.first] = 0;
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pii> > adjM(101);
        for(auto f: flights)
            adjM[f[0]].emplace_back(f[1], f[2]); 
        vector<int> vis(101, 0);
        vis[src] = 1;
        int ans = INT_MAX/2;
        dfs(src, dst, K+1,0, ans, adjM, vis);
        if(ans == INT_MAX/2)    return -1;
        return ans;
    }
};
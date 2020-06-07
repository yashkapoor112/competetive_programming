/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - Remove redundant edeges
Problem Link - https://leetcode.com/problems/redundant-connection/

*/
class Solution {
public:
    vector<int> vis;
    vector<int> ans;
    vector<vector<int> > graph;
    void find(int start, int end, int actual)
    {
        vis[start] = 1;
        vis[end] = 1;
        for(int i = 0; i < graph[start].size(); i++){
            if(vis[graph[start][i]] && graph[start][i] == end && start != actual){
                ans[0] = actual;
                ans[1] = end;
                return;
            }
            else if(!vis[graph[start][i]])
                find(graph[start][i], end, actual);
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size()+1;
        graph.resize(len+1);
        ans.resize(2);
        for(auto e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(auto e: edges){
            vis.assign(len, 0);
            find(e[0], e[1], e[0]);
        }
        return ans;
    }
};
/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - 

Problem Link - https://leetcode.com/problems/largest-divisible-subset/

Similar to LIS(with sorting)
Note - Sorting works as we need a subset(subsequence) ans not subarray.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(!nums.size())    return {};
        sort(nums.begin(), nums.end());
        vector<vector<int> > dpp(nums.size());
        for(int i = 0; i < dpp.size(); i++)     dpp[i] = {nums[i]};
        vector<int> anss = dpp[0];
        int idx = 0, ans = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 || nums[j]%nums[i] == 0){
                    if(dpp[i].size() < dpp[j].size()+1){
                        dpp[i] = dpp[j];
                        dpp[i].push_back(nums[i]);
                    }
                    if(dpp[i].size() > anss.size())
                        anss = dpp[i];
                }
            }   
        }
        return anss;
    }
};
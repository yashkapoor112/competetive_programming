/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - 

Problem Link - https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

*/

class Solution {
public:
    int dp[100011];
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> presum;
        presum.push_back(0);
        for(int i = 0; i < arr.size(); i++)
            presum.push_back(presum.back()+arr[i]);
        
        memset(dp, 0x3f, sizeof dp);
        int left = 0, ans = dp[0];
        for(int right = 1; right < presum.size();right++){
            while(presum[right] - presum[left] > target)
                left++;
            if(presum[right] - presum[left] == target){
                ans = min(ans, right-left + dp[left]);
                dp[right] = min(dp[right-1], right-left);
            }
            else    dp[right] = dp[right-1];
            
        }    
        if(ans == dp[0])    return -1;
        return ans;
    }
};
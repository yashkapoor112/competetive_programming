/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - Given a non-empty array containing only positive integers, find if 
the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Problem Link - https://leetcode.com/problems/partition-equal-subset-sum/

Iterative DP is missing

*/

class Solution {
public:
    int dp[20001][201];
    bool helper(int left, int idx, vector<int>& nums, int maxAns){
        if(idx == nums.size()){
            if(left == maxAns)   return true;
            return false;
        }
        if(left > maxAns)   return false;
        if(dp[left][idx] != -1)  return dp[left][idx];
        else{
            int ans = helper(left+nums[idx], idx+1, nums, maxAns) || helper(left, idx+1, nums, maxAns);
            return dp[left+nums[idx]][idx] = ans;
        }
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int maxAns = accumulate(nums.begin(), nums.end(), 0);
        if((maxAns)%2)   return false;
        sort(nums.rbegin(), nums.rend());
        return helper(0, 0, nums, maxAns/2);
    }
};



//Without Memoization TLE
class Solution {
public:
    bool helper(int left, int idx, vector<int>& nums, int maxAns){
        if(left == maxAns)   return true;
        if(idx == nums.size())  return false;
        if(left > maxAns)   return false;
        return helper(left+nums[idx], idx+1, nums, maxAns) || helper(left, idx+1, nums, maxAns);
    }
    bool canPartition(vector<int>& nums) {
        int maxAns = accumulate(nums.begin(), nums.end(), 0);
        if((maxAns)%2)   return false;
        sort(nums.rbegin(), nums.rend());
        return helper(0, 0, nums, maxAns/2);
    }
};


//Without memozation accepted 4ms
class Solution {
public:
    bool helper(int left, int idx, vector<int>& nums, int maxAns){
        if(idx == nums.size())  return false;
        if(maxAns-left == nums[idx])    return true;    
        if(nums[idx] > (maxAns-left)) return false;     //key difference eliminating one extra branch
        return helper(left+nums[idx], idx+1, nums, maxAns) || helper(left, idx+1, nums, maxAns);
    }
    bool canPartition(vector<int>& nums) {
        int maxAns = accumulate(nums.begin(), nums.end(), 0);
        if((maxAns)%2)   return false;
        sort(nums.rbegin(), nums.rend());
        return helper(0, 0, nums, maxAns/2);
    }
};
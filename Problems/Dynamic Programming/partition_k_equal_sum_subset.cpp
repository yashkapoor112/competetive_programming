/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - Given an array of integers nums and a positive integer k, f
ind whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Problem Link - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

Bit Masking DP is a better solution

*/
class Solution {
public:
    bool canPart(int ni, vector<int>ssum, vector<int> nums, int total, int target)
    {
        if(ni == nums.size())   return true;
        for(int j = 0; j < ssum.size(); j++){
            if((nums[ni]+ssum[j]) <= target){
                ssum[j]+=nums[ni];
                if(canPart(ni+1, ssum, nums, total, target))
                    return true;
                ssum[j]-=nums[ni];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> ssum(k,0);
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total/k;
        if(total%k) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        return canPart(0, ssum, nums, total, target);;
    }
};
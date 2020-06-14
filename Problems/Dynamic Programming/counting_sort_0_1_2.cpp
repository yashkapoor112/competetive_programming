/*
Source code by Yash Kapoor

Codeforces      yk112
Leetcode        yk112
Codechef        yashkapoor112

Problem Statement - 

Problem Link - https://leetcode.com/problems/sort-colors/

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int i = 0;
        while(i <= end && start < end){
            if(nums[i] == 0){
                nums[i] = nums[start];
                nums[start] = 0;
                start++;
                i++;
            }
            else if(nums[i] == 2){
                nums[i] = nums[end];
                nums[end] = 2;
                end--;
            }
            else    i++;
        }
    }
};
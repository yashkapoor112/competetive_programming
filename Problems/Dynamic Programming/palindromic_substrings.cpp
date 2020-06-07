/*
Source code by Yash Kapoor

Codeforces  	yk112
Leetcode  		yk112
Codechef 	 	yashkapoor112

Problem Statement - Number of Palindromic Substrings
Problem Link - https://leetcode.com/problems/palindromic-substrings/

*/
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
        for(int i = 0; i < s.length(); i++)
            dp[i][i] = 1;
        
        int i = 0, j = 0, ans = s.length();
        for(int k = 1; k < s.length(); k++){
            j = k, i = 0;
            while(i < s.length() && j < s.length()){
                if(s[i] == s[j])
                    if((j - i) == 1)    dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1];
                ans += dp[i++][j++];
            }
        }
        return ans;
    }
};

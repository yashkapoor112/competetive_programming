/*
Source code by Yash Kapoor
Codeforces   yk112
Leetcode     yk112
Codechef     yashkapoor112
Problem Statement - 
Problem Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

*/
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define DEBUG(x) cout << ">" << #x << ": " << x << endl;
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define fi first
#define se second

#define ll long long
#define ull unsigned long long
#define rint register int
#define rll register long long

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define optimise_l1 __attribute__((optimize("-O3")))
#define optimise_l2 __attribute__((optimize("-Ofast")))
#define optimise_l3 __attribute__((optimize("-Omax")))
#define optimise_l4 __attribute__((optimize("-O2")))

using namespace std;

class Solution
{
public:
    /* Given
        Weights of items
        number of days mandatory to complete the task

        find the capacity to complete this task in the number of days
    */
    bool ifSatisfiedByMid(int capacity, vector<int> &weights, int days)
    {
        int days_count = 0, weight_cap = 0;
        for (int &weight : weights)
        {
            if (days_count > days || weight > capacity)
                return false;
            if (weight + weight_cap > capacity)
            {
                days_count++;
                weight_cap = 0;
            }
            weight_cap += weight;
        }
        return days_count + 1 <= days;
    }

    int solve(int left, int right, vector<int> &weights, int days)
    {
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (ifSatisfiedByMid(mid, weights, days))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int min_capacity = 1, max_capacity = 50000 * 500;
        return solve(min_capacity, max_capacity, weights, days);
    }
};

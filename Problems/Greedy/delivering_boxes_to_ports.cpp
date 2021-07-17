/*
Source code by Yash Kapoor
Codeforces   yk112
Leetcode     yk112
Codechef     yashkapoor112
Problem Statement - 
Problem Link - 

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
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        int prev, i = 0, nob = 1;
        while (i < boxes.size())
        {

            if (i > 0)
            {
                if (boxes[i][0] == boxes[i - 1][0])
                {
                    if (boxes[i][1] + boxes[i - 1][1] <= maxWeight && nob + 1 <= maxBoxes)
                    {
                        boxes[i - 1][1] += boxes[i - 1][1];
                        nob += 1;
                    }
                    else if (nob != 1)
                    {
                        boxes.erase(boxes.begin() + i);
                    }
                }
                else
                {
                    nob = 1;
                }
            }
        }

        int ans = 0;
        int weight = 0;
        i = 0, nob = 0;

        while (i < boxes.size())
        {

            while (i < boxes.size() && nob + 1 <= maxBoxes && weight + boxes[i][1] <= maxWeight)
            {
                nob += 1;
                weight += boxes[i][1];
                i++;
                ans += 1;
            }
            nob = 0;
            weight = 0;
            ans += 1;
        }
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
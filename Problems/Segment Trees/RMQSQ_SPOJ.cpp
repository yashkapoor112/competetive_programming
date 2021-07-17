/*
Source code by Yash Kapoor
Codeforces   yk112
Leetcode     yk112
Codechef     yashkapoor112
Problem Statement - 
Problem Link - https://www.spoj.com/problems/RMQSQ/

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

int st[400004] = {0};
int query(int index, int qs, int qe, int cs, int ce)
{
    if (qe < cs || qs > ce)
        return INT_MAX; //completely outside

    if (qs <= cs && qe >= ce)
        return st[index]; //completely inside the l, r querry range

    int mid = cs + (ce - cs) / 2;
    int leftMin = query(2 * index + 1, qs, qe, cs, mid);
    int rightMin = query(2 * index + 2, qs, qe, mid + 1, ce);

    return min(leftMin, rightMin);
}
void build(int n, int index, int l, int r, vector<int> &arr)
{
    if (l == r)
    {
        st[index] = arr[l];
        return;
    }

    int mid = l + ((r - l) / 2);
    build(n, 2 * index + 1, l, mid, arr);
    build(n, 2 * index + 2, mid + 1, r, arr);

    st[index] = min(st[2 * index + 1], st[2 * index + 2]);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //minimum number in a range

    int n, q;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(n, 0, 0, n - 1, arr);

    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, l, r, 0, n - 1) << endl;
    }
}
/*
Source code by Yash Kapoor
Codeforces   yk112
Leetcode     yk112
Codechef     yashkapoor112
Problem Statement - 
Problem Link - https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

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
    struct trie
    {
        unordered_map<char, trie *> child;
        int freq = false;

        trie()
        {
            freq = 0;
        }
    };
    struct trie *root;
    void insert(string s)
    {
        struct trie *cur = root;
        for (char ch : s)
        {
            if (cur->child[ch] == NULL)
                cur->child[ch] = new trie;
            cur->freq += 1;
            cur = cur->child[ch];
        }
        cur->freq += 1;
    }

    void findCommonSubstring(struct trie *cur, string s, int mismatch, int &ans, int i)
    {
        if (mismatch == 1)
            ans += cur->freq;
        if (mismatch > 1 || i >= s.length())
            return;
        for (auto itr : cur->child)
        {
            // comparing first character of search string with first alphabet in root of trie
            // if there is a match then we will consider the second char of search string with the child of first one
            // if not then we move on to the next element of the root of trie
            if (itr.first == s[i])
            {
                //match found move on to next
                findCommonSubstring(itr.second, s, mismatch, ans, i + 1);
            }
            else
            {
                findCommonSubstring(itr.second, s, mismatch + 1, ans, i + 1);
                // match not found move on to next with only one more chance
            }
        }
    }

    int countSubstrings(string s, string t)
    {
        root = new trie;
        int slen = s.length();
        int tlen = t.length();
        for (int i = 0; i < s.length(); i++)
            insert(s.substr(i, slen)); // inserting substring 0 .. last 1 .. last 2 .. last
        int ans = 0;
        for (int i = 0; i < t.length(); i++)
            findCommonSubstring(root, t.substr(i, tlen), 0, ans, 0); // searching substring 0 .. last 1 .. last 2 .. last

        return ans;
    }
};

class Solution2
{
    // two pointer approach
public:
    int countSubstrings(string s, string t)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < t.length(); j++)
            {
                int x, y;
                x = i, y = j;
                int mismatch = 0;
                while (x < s.length() && y < t.length())
                {
                    if (s[x] != t[y])
                        mismatch += 1;
                    if (mismatch > 1)
                        break;
                    if (mismatch == 1)
                        ans += 1;
                    x++;
                    y++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    Solution ob;

    string str1;
    cin >> str1;
    string str2;
    cin >> str2;

    ob.countSubstrings(str1, str2);

    return 0;
}
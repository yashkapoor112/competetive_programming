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

struct trie
{
    unordered_map<char, trie *> child;
    bool isEnd; // can be int if we need frequency

    trie() // either we can do this or we can create a function and get the new node
    {      // with this function we can use the new operator and also initialise the node together
        isEnd = false;
    }
};

struct trie *root;

void insert(string str)
{
    struct trie *cur = root;
    for (char ch : str)
    {
        if (cur->child[ch] == NULL)
        {
            cur->child[ch] = new trie; // this will call the struct constructor and also initialise the variables
                                       // if the constructor is not mentioned then new operator will call the default constructor but it will not initialise anything
        }
        cur = cur->child[ch];
    }
    cur->isEnd = true;
}

bool search(string str)
{
    struct trie *cur = root;
    for (char ch : str)
    {
        if (cur->child[ch] == NULL)
            return false;
        cur = cur->child[ch];
    }
    return cur->isEnd;
}

int main()
{
    root = new trie;
    // we would have to intialise the root here if the default constructor was not defined
    int n;
    cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        insert(str);
    }
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (search(str) == false)
            cout << "Not Present" << endl;
        else
            cout << "Present" << endl;
    }
    return 0;
}

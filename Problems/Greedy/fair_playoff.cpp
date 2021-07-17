/*
Source code by Yash Kapoor

Codeforces		yk112
Leetcode		yk112
Codechef		yashkapoor112

Problem Statement - 
Problem Link - https://codeforces.com/problemset/problem/1535/A

*/
#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define optimise_l1 __attribute__((optimize("-O3")))
#define optimise_l2 __attribute__((optimize("-Ofast")))
#define optimise_l3 __attribute__((optimize("-Omax")))
#define optimise_l4 __attribute__((optimize("-O2")))

using namespace std;

int optimise_l1 main()
{
	fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	rint t;
	cin >> t;
	vector<int> arr(4);
	
	for (rint i = 0; i < t; ++i)
	{
		rint first_max = INT_MIN, second_max = INT_MIN;
		for (rint i = 0; i < 4; ++i)
		{
			cin >> arr[i];	
			if(arr[i] > first_max){
				second_max = first_max;
				first_max = arr[i];
			}
			else if (arr[i] > second_max)
				second_max = arr[i];
		}
		if((arr[0] == second_max && arr[1] == first_max) ||
			(arr[1] == second_max && arr[0] == first_max) ||
			(arr[2] == second_max && arr[3] == first_max) ||
			(arr[3] == second_max && arr[2] == first_max))
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
	
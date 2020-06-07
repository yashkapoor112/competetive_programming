#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;	
    	vector<int> A(n, 0);
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> A[i];
    	}
    	sort(A.begin(), A.end());
    	int ans = INT_MAX;
    	for (int i = 1; i < n; ++i)
    	{
    		ans = min(A[i] - A[i-1], ans);
    	}
    	cout << ans << endl;
    }

    return 0;
}
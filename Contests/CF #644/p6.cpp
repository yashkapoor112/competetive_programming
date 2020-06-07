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
    	int n, m;
    	cin >> n >> m;
    	vector<string> A(n);
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> A[i];
    	}
    	vector<char> freq(m);
    	unordred_map<int, set<char> > fr;
    	for (int i = 0; i < m; ++i)
    	{
    		freq[i] = A[0][i];
    		fr[j].insert(A[0][i]);
    	}
    	int cnt;
    	int changed = 0;
    	for (int i = 1; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			fr[j].insert(A[i][j]);
    		}
    	}
    	for(int i = 0; i < m; i++)
    	{
    		if(fr[j].size() == n )
    		{
    			freq[j] = 'z';
    		}
    	}
    	if(cnt > 1)
    		cout << "-1" << endl;
    	else
    	{
    		for (int i = 0; i < m; ++i)
    		{
    			cout << freq[i];
    		}
    		cout << endl;
    	}
    }

    return 0;
}
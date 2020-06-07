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
    	vector<string> A(n);
   		for (int i = 0; i < n; ++i){
   			cin >> A[i];
   		}
   		int flag = 0;
   		for (int i = 0; i < n; ++i)
   		{
   			for (int j = 0; j < n; ++j)
   			{
   				if(A[i][j] == '1')
   				{
   					if(i == n-1 || j == n-1 || A[i+1][j] == '1' || A[i][j+1] == '1')
   						continue;
   					else
   					{
   						flag = 1;
   						break;
   					}
   				}
   			}
   			if(flag)
   				break;
   		}
   		if(flag)
   			cout << "NO" << endl;
   		else
   			cout << "YES" << endl;

    }

    return 0;
}
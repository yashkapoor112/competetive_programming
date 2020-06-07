#include <bits/stdc++.h>
#define ll long long
using namespace std;
int primeFactors(int n, int k){
	int ans = INT_MAX;
	for (int i = 1; i < sqrt(n)+1 && i <= k; ++i){
		if(n%i == 0){
			if(n/i > k)  ans = min(n/i, ans);
			else ans = min(ans, i);
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	cout << primeFactors(n, k) << endl;
    }

    return 0;
}
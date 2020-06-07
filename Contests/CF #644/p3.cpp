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
    while(t--){
    	int n;
    	cin >> n;
    	vector<int> A(n);
    	int e = 0, o = 0;
    	for (int i = 0; i < n; ++i){
    		cin >> A[i];
    		if(A[i] % 2 == 0)	e++;
    		else	o++;
    	}
    	if(e%2 == 0 && o%2 == 0)	cout << "YES" << endl;
    	else if(e%2 != 0 && o%2 != 0){
    		int c = 0;
    		e--;
    		o--;
    		sort(A.begin(), A.end());
    		for (int i = 0; i < n-1; ++i){
    			if(A[i]+1 == A[i+1]){
    				c++;
    				i+=1;
    			}
    		}
    		if(e + o + (c*2) >= n)	cout << "YES" << endl;
    		else	cout << "NO" << endl;
    	}
    	else	cout << "NO" << endl;

    }

    return 0;
}
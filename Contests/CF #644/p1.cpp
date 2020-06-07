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
    	int a,b;
    	cin >> a >> b;
    	if(b+b <= a)	cout << a*a << endl;
    	else if(a+a <= b)	cout << b*b << endl;
    	else	cout << min({((a+a) * (a+a)), ((b+b)*(b+b)), ((a+b) * (a+b)) }) << endl;
    }

    return 0;
}
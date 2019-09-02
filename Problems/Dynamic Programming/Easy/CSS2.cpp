/*
Source code by Yash Kapoor
Problem Statement - 
Problem Link - 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	
	int n,m;
	cin >> n >> m;
	int id,attr,val,priority;
	int max_val=0;
	int final_val ;
	while(m--)
	{
		cin >> id >> attr >> val >> priority;
		if(max_val <= priority)
		{
			final_val = val;
		}
		
	}
	cout << final_val << endl;

}
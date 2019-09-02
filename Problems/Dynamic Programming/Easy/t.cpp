/*
Source code by Yash Kapoor
Problem Statement - 
Problem Link - 
*/
#include<bits/stdc++.h>
#define ll long long
#include <unordered_map>
using namespace std;

vector<int> getMinimumDifference(vector<string> a, vector<string> b){

	int len = a.size();
	unordered_map<char, int> a1;
	unordered_map<char, int> a2;

	int min_len = min(a.size(), b.size());
	int max_len = max(a.size(), b.size());
	vector<int> vic(max_len , -1);

	for (int i = 0; i < min_len; ++i)
	{
		string c1 = a[i];
		string c2 = b[i];
		int l1=c1.length();
		int l2=c2.length();
		if(l1!=l2)
		{
			continue;
		}
		unordered_map<char, int> m;

 
		for (int i = 0; i < l1; ++i)
		{
			m[c1[i]]++;
		}
		for (int i = 0; i < l2; ++i)
		{
			m[c2[i]]--;
		}
		int sum = 0;
		for(auto itr = m.begin();itr!=m.end();itr++)
		{
			sum += abs(itr->second);
		}
		vic[i]=sum;
	}
	return vic;
}

int main()
{
	vector<string> a;
	vector<string> b;
	a.push_back("a");
	a.push_back("jk");
	a.push_back("abb");
	a.push_back("mn");
	a.push_back("abc");
	a.resize(5);
	b.push_back("bb");
	b.push_back("kj");
	b.push_back("bbc");
	b.push_back("op");
	b.push_back("def");
	b.resize(5);

	
	vector<int> arr = getMinimumDifference(a,b);
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	

	
}
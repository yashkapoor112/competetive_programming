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
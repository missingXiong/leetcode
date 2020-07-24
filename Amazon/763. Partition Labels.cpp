

vector<int> partitionLabels(string S)
{
	if(S.length() == 0) return {};
	int len = S.length();
	
	unordered_map<char, int> m;
	for(int i = 0; i < len; i++)
		m[len[S]] = i;
	int first = -1, last = 0;   // 可以用count计数
	vector<int> ans;
	for(int i = 0; i < len; i++)
	{
		last = max(last, m[S[i]]);
		if(i == last)
		{
			ans.push_back(last - first);
			first = last;
		}
	}
	return ans;
}
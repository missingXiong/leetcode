vector<int> findAnagrams(string s, string p)
{
	int len_s = s.length();
	int len_p = p.length();
	if (len_s == 0 || len_p == 0) return {};
	
	vector<int> pattern(26, 0);
	for (char c : p) ++pattern[c - 'a'];
	
	vector<int> dict(26, 0);
	vector<int> ans;
	for (int i = 0; i < len_s; i++)
	{
		if (i >= len_p)
			--dict[s[i - len_p] - 'a'];
		++dict[s[i] - 'a'];
		
		if (dict == pattern) ans.push_back(i - len_p + 1);
	}
	return ans;
}
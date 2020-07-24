
vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
{
	unordered_set<string> dict(words.begin(), words.end());
	
	vector<string> ans;
	for(const string& s : words)
	{
		dict.erase(s);
		if(canBreak(s, dict)) ans.push_back(s);
		dict.insert(s);
	}
	return ans;
}


// 139. word break
bool canBreak(const string& s, const unordered_set<string>& dict)
{
	if(dict.size() == 0) return false;
	if(s.length() == 0) return false;
	
	int n = s.length();
	vector<bool> dp(n + 1, false);
	dp[0] = true;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(dp[j] && dict.count(s.substr(j, i - j)))
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[n];
}
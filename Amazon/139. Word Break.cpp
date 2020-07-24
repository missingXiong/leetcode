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

// DFS + memoization
bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	return search(s, dict);
}

unordered_map<string, bool> memo;
bool search(const string& s, const unordered_set<string>& dict)
{
	if(memo.count(s)) return memo[s];
	if(dict.count(s)) return memo[s] = true;
	
	for(int j = 1; j < s.length(); j++)
	{
		const string left = s.substr(0, j);
		const string right = s.substr(j);
		
		if(dict.count(left) && search(right, dict))
			return memo[s] = true;
	}
	
	return memo[s] = false;
}
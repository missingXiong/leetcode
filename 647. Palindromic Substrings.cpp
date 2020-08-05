int countSubstrings(string s)
{
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	
	int count = n;
	for (int len = 2; len <= n; len++)
	{
		for (int i = 0; i <= n - len; i++)
		{
			int j = len + i - 1;
			if (s[i] == s[j] && (i + 1 > j - 1 || dp[i + 1][j - 1]))
				dp[i][j] = true;
			
			if (dp[i][j]) count++;
		}
	}
	
	return count;
}
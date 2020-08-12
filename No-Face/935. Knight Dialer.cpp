
int knightDialer(int N)
{
	const int nums = 10;
	const int mod = 1e9 + 7;
	vector<vector<int>> dicts = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
	vector<vector<int>> dp(2, vector<int>(nums , 0));
	for(int i = 0; i < nums; i++)
		dp[1][i] = 1;
	
	int old = 0, now = 1;
	for(int i = 2; i <= N; i++)
	{
		old = now;
		now = 1 - now;
		
		for(int j = 0; j < nums; j++)
		{
			dp[now][j] = 0;
			for(int v : dicts[j])
				dp[now][j] = (dp[old][v] % mod + dp[now][j] % mod) % mod;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < nums; i++)
		ans = (ans % mod + dp[now][i] % mod) % mod;
	return ans;
}
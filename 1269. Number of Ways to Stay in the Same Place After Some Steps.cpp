int numWays(int steps, int arrLen)
{
	int len = min(steps / 2, arrLen - 1);
	vector<vector<int>> dp(step + 1, vector<int>(len + 1, 0));
	dp[0][0] = 1;
	
	for(int s = 1; s <= steps; s++)
	{
		for(int i = 0; i <= len; i++)
		{
			dp[s][i] = dp[s - 1][i];
			if(i > 0) dp[s][i] += dp[s - 1][i - 1];
			if(i < len) dp[s][i] += dp[s - 1][i + 1];
		}
	}
	
	return dp[steps][0];
}


int numWays(int steps, int arrLen)
{
	int len = min(steps / 2, arrLen - 1);
	vector<vector<int>> dp(2, vector<int>(len + 1, 0));
	dp[0][0] = 1;
	
        const int mod = 1e9 + 7;
	int old = 0, now = 0;
	for(int s = 1; s <= steps; s++)
	{
		old = now; 
		now = 1 - old;
		for(int i = 0; i <= len; i++)
		{
			dp[now][i] = (dp[old][i]) % mod;
			if(i > 0) 
                dp[now][i] = ((dp[now][i] % mod) + (dp[old][i - 1] % mod)) % mod;
			if(i < len) 
                dp[now][i] = ((dp[now][i] % mod) + (dp[old][i + 1] % mod)) % mod;
		}
	}
	
	return dp[now][0];
}

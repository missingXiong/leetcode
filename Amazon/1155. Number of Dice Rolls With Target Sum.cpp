

int numRollsToTarget(int d, int f, int target)
{
	const int mod = 1000000007;
	// dp[i][j]掷j次得到i的方式数
	vector<vector<int>> dp(target + 1, vector<int>(d + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= target; i++)
	{
		for(int j = 1; j <= d; j++)
		{
			for(int k = 1; k <= f; k++)
			{
				if(i >= k)
					dp[i][j] = ((dp[i][j] % mod) + (dp[i - k][j - 1] % mod)) % mod;
			}
		}
	}
	return dp[target][d];
}
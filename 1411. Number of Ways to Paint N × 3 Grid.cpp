int numOfWays(int n)
{
	const int mod = 1e9 + 7;
	vector<vector<int>> dp(2, vector<int>(27, 0));
	
	for(int p = 0; p < 27; p++)
	{
		if(selfOK(p)) dp[0][p] = 1;
	}
	
	int old = 0, now = 0;
	for(int i = 1; i < n; i++)
	{
		old = now;
		now = 1 - now;
		for(int p = 0; p < 27; p++)
		{
            dp[now][p] = 0;
			if(!selfOK(p)) continue;
			for(int q = 0; q < 27; q++)
			{
				if(selfOK(q) && crossOK(p, q))
				{
					dp[now][p] = (dp[now][p] + dp[old][q]) % mod;
				}
			}
		}
	}
	
	int ans = 0;
	for(int p = 0; p < 27; p++)
		ans = (ans + dp[now][p]) % mod;
	return ans;
}

bool selfOK(int p)
{
	int c1 = p / 9;
	int c2 = p / 3 % 3;
	int c3 = p % 3;
	return c1 != c2 && c2 != c3;
}

bool crossOK(int p, int q)
{
	int a1 = p / 9;
	int a2 = p / 3 % 3;
	int a3 = p % 3;
	
	int b1 = q / 9;
	int b2 = q / 3 % 3;
	int b3 = q % 3;
	return a1 != b1 && a2 != b2 && a3 != b3;
}
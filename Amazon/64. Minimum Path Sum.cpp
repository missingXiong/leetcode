

int minPathSum(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	
	vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
	dp[0][0] = grid[0][0];
	for(int i = 1; i < m; i++)
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	for(int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
	}
	return dp[m - 1][n - 1];
}

int minPathSum(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	
	vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	
	int old = 0, now = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			// dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			if(i == 0 && j == 0)
			{
				dp[now][j] = grid[i][j];
				continue;
			}
			
			dp[now][j] = INT_MAX;    // 注意初始化，避免之前的结果影响后面的计算结果
			if(i > 0)
				dp[now][j] = min(dp[now][j], dp[old][j] + grid[i][j]);
			if(j > 0)
				dp[now][j] = min(dp[now][j], dp[now][j - 1] + grid[i][j]);
		}
		old = now;
		now = 1 - now;
	}
	return dp[old][n - 1];
}
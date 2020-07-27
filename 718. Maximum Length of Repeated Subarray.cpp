int findLength(vector<int>& A, vector<int>& B)
{
	if(A.size() == 0 || B.size() == 0) return 0;
	
	int m = A.size(), n = B.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	
	int ans = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else 
				dp[i][j] = 0;
		}
	}
	return ans;
}


int findLength(vector<int>& A, vector<int>& B)
{
	if(A.size() == 0 || B.size() == 0) return 0;
	
	int m = A.size(), n = B.size();
	vector<vector<int>> dp(2, vector<int>(n + 1, 0));
	
	int ans = 0;
	int old = 0, now = 0;
	for(int i = 1; i <= m; i++)
	{
		old = now;
		now = 1 - old;
		for(int j = n; j >= 1; j--)
		{
			if(A[i - 1] == B[j - 1])
			{
				dp[now][j] = dp[old][j - 1] + 1;
				ans = max(ans, dp[now][j]);
			}
			else
				dp[now][j] = 0;
		}
	}
	
	return ans;
}













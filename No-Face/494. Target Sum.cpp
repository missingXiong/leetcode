
int findTargetSumWays(vector<int>& nums, int S)
{
	int size = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (abs(sum) < S || (S + sum) % 2) return 0;
	int target = (sum + S) / 2;    // (sum + s) must be even
	
	vector<vector<int>> dp(size + 1, vector<int>(target + 1, 0));
	dp[0][0] = 1;   // dp[i > 0][0] may > 1(eg: {0, 0, 0, 0})
	
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j <= target; j++)
		{
			dp[i][j] += dp[i - 1][j];
			if (j >= nums[i - 1])
			{
				dp[i][j] += dp[i - 1][j - nums[i - 1]];
			}
		}
	}
	
	return dp[size][target];
}

// according to tological order : space complexity can be optimized
// topo order : from top -> down, rear -> front 
int findTargetSumWays(vector<int>& nums, int S)
{
	int size = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (abs(sum) < S || (S + sum) % 2) return 0;
	int target = (sum + S) / 2;    // (sum + s) must be even
	
	vector<vector<int>> dp(2, vector<int>(target + 1, 0));
	dp[0][0] = 1;
	
	int old = 0, now = 0;
	for (int i = 1; i <= size; i++)
	{
		old = now;
		now = 1 - now;
		for (int j = target; j >= 0; j--)
		{
			dp[now][j] = dp[old][j];    // need reset dp[now][j]
			if (j >= nums[i - 1])
			{
				dp[now][j] += dp[old][j - nums[i - 1]];
			}
		}
	}
	
	return dp[now][target];
}








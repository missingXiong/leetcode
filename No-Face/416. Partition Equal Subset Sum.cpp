bool canPartition(vector<int>& nums)
{
	int size = nums.size();
	if (size == 0) return false;
	
	int sum = 0;
	for (int num : nums) sum += num;
	if (sum % 2) return false;
	
	int target = sum / 2;
	vector<vector<bool>> dp(size + 1, vector<bool>(target + 1, false));

	for (int i = 0; i <= size; i++)
		dp[i][0] = true;
	
	// space can be optimized to O(target)
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= target; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= nums[i - 1])
				dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
		}
	}
	return dp[size][target];
}
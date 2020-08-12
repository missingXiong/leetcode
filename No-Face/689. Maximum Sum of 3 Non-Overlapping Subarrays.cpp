vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
{
	int n = nums.size();
	int size = n - k + 1;
	vector<int> dp(size, 0);

	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		
		if (i >= k)
			sum -= nums[i - k];
		
		if (i >= k - 1)
			dp[i - k + 1] = sum;
	}
		
	vector<int> left(size, 0);
	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (dp[i] > dp[maxIndex])
			maxIndex = i;
		left[i] = maxIndex;
	}
	
	vector<int> right(size, 0);
	maxIndex = size - 1;
	for (int i = size - 1; i >= 0; i--)
	{
		if(dp[i] >= dp[maxIndex])
			maxIndex = i;
		right[i] = maxIndex;
	}
	
	vector<int> ans(3, 0);
	int max = 0;
	for (int i = k; i <= n - 2 * k; i++)
	{
		int middle_sum = 0;
		for (int j = i; j < i + k; j++)
			middle_sum += nums[j];
		
		int left_index = left[i - k];
		int right_index = right[i + k];
		int curr_sum = dp[left_index] + middle_sum + dp[right_index];
		
		if(curr_sum > max)
		{
			max = curr_sum;
			ans[0] = left_index;
			ans[1] = i;
			ans[2] = right_index;
		}
	}
	
	return ans;
}
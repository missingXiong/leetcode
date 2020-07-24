

int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(2, 0);
	dp[0] = nums[0];
	int ans = dp[0];
	int old = 0, now = 0;
	for(int i = 1; i < n; i++)
	{
		old = now;
		now = 1 - now;
		dp[now] = max(nums[i], nums[i] + dp[old]);
		ans = max(ans, dp[now]);
	}
		
	return ans;
}

// Kadane's Algorithm
int maxSubArray(vector<int>& nums)
{
	int curr_sum = 0, best_sum = INT_MIN;
	for(int num : nums)
	{
		curr_sum += num;
		best_sum = max(curr_sum, best_sum);
		if(curr_sum < 0) curr_sum = 0;
	}
	return best_sum;
}

// find the exact subarray
vector<int> findMaxSubarray(vector<int>& nums)
{
	int best_sum = INT_MIN;
	int best_start = 0, best_end = 0;
	int curr_sum = 0;
	int curr_start = 0, curr_end = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(curr_sum <= 0)
		{
			curr_start = curr_end = i;
			curr_sum = nums[i];
		}
		else
		{
			curr_sum += nums[i];
			curr_end++;
		}
		
		if(curr_sum > best_sum)
		{
			best_sum = curr_sum;
			best_start = curr_start;
			best_end = curr_end;
		}
	}
	
	vector<int> ans(nums.begin() + best_start, nums.begin() + best_end + 1);
	return ans;
}
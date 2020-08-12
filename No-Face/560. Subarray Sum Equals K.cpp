
// O(n^2)
int subarraySum(vector<int>& nums, int k)
{
	int size = nums.size();
	vector<int> prefix(size + 1, 0);
	for (int i = 0; i < size; i++)
		prefix[i + 1] = prefix[i] + nums[i];
	
	int ans = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (prefix[j + 1] - prefix[i + 1] == k)
				ans++;
		}
	}
	
	return ans;
}


// 
int subarraySum(vector<int>& nums, int k)
{
	unordered_map<int, int> prefix_cnt = {{0, 1}};   // <prefix, count>
	size_t size = nums.size();
	int sum = 0, ans = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += nums[i];
		if (prefix_cnt.count(sum - k))
			ans += prefix_cnt[sum - k];
		++prefix_sum[sum];
	}
	
	return ans;
}
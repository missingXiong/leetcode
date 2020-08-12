int subarraySum(vector<int>& nums, int k)
{
	int size = nums.size();
	
	int right = 0;
	int sum = 0;
	int res = 0;
	for (int left = 0; left < size; left++)
	{
		while (right < size && sum < k)
			sum += nums[right++];
		
		if (sum == k)
			res++;
		
		sum -= nums[left];
	}
	
	return res;
}
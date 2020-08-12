int pivotIndex(vector<int>& nums) 
{
	int size = nums.size();
	if(size == 0) return -1;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	
	int ans = size;
	int left_sum = sum, right_sum = 0; 
	for(int i = size - 1; i >= 0; i--)
	{
		left_sum -= nums[i];
		if(i + 1 < size) right_sum += nums[i + 1];
		
		if(left_sum == right_sum) ans = min(ans, i);
	}
	
	return ans == size ? -1 : ans;
}
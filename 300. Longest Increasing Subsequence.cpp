
// O(nlogn) solution
int lengthOfLIS(vector<int>& nums)
{
        	int size = nums.size();
    if(size == 0) return 0;
	vector<int> tail(size, 0);
	tail[0] = nums[0];
	int length = 1;
	
	for(int i = 1; i < size; i++)
	{
		if(nums[i] < tail[0])
			tail[0] = nums[i];
		else if(tail[length - 1] < nums[i])
			tail[length++] = nums[i];
		else
		{
			// may have same elements in nums array
			// Attention: search the lower_bound in [begin(), begin() + length)
			auto p = lower_bound(tail.begin(), tail.begin() + length, nums[i]);
			*p = nums[i];
		}	
	}
	
	return length;
}
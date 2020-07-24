

int firstMissingPositive(vector<int>& nums)
{
	if(nums.size() == 0) return 1;
	
	for(int i = 0; i < nums.size(); i++)
	{
		while(nums[i] > 0 && nums[i] <= nums.size() // 注意是while循环
			  && nums[nums[i] - 1] != nums[i])  // 注意：不能写成nums[i] - 1 != i
			// concer case : 1 1  会陷入死循环，要保证要交换的数不相等
		{
			int index = nums[i] - 1;
			swap(nums[index], nums[i]);
		}
	}
	
	for(int i = 0; i < nums.size(); i++)
	{
		if(i + 1 != nums[i])
			return i + 1;
	}
	return nums.size() + 1;
}
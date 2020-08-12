
int missingElement(vector<int>& nums, int k)
{
	int size = nums.size();
	for(int i = 0; i < size - 1; i++)
	{
		int gap = nums[i + 1] - nums[i] - 1;
		if(k <= gap)
			return nums[i] + k;
		
		k -= gap;
	}
	
	return nums[size - 1] + k;
}

// binary search: find the last element whose gap with nums[0] smaller than k
int missingElement(vector<int>& nums, int k)
{
	int low = 0, high = nums.size();
	int index = -1;
	while(low < high)
	{
		int middle = low + (high - low) / 2;
		
		// calculate the gap between nums[0] and nums[middle]
		int gap = nums[middle] - nums[0] - middle;
		if(gap < k)
		{
			index = middle;
			low = middle + 1;
		}
		else high = middle;
	}
	
	if(index == -1)   // each gaps is greater than k
		return nums[0] + k;
	else
	{
		int gap = nums[index] - nums[0] - index;
		return nums[index] + k - gap;
	}
}




















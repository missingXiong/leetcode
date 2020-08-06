

int singleNonDuplicate(vector<int>& nums)
{
	int size = nums.size();
	int low = 0, high = nums.size() - 1;
	while (low <= high)
	{
		int middle = low + (high - low) / 2;
		if ((middle - 1 < 0 || nums[middle - 1] != nums[middle]) 
			&& (middle + 1 >= size || nums[middle + 1] != nums[middle]))
			return nums[middle];
		
		if (middle % 2)
		{
			if (middle - 1 >= 0 && nums[middle] == nums[middle - 1])
				low = middle + 1;
			else
				high = middle - 1;
		}
		else
		{
			if (middle - 1 >= 0 && nums[middle] == nums[middle - 1])
				high = middle - 1;
			else
				low = middle + 1;
		}
		

	}
	
	return -1;
}


int singleNonDuplicate(vector<int>& nums)
{
	int size = nums.size();
	int low = 0, high = nums.size() - 1;
	while (low <= high)
	{
		int middle = low + (high - low) / 2;
		if ((middle - 1 < 0 || nums[middle - 1] != nums[middle]) 
			&& (middle + 1 >= size || nums[middle + 1] != nums[middle]))
			return nums[middle];

		// already deal with the edge case, so we don't need check middle - 1 and middle + 1
		if (middle % 2 && nums[middle] == nums[middle - 1] || middle % 2 == 0 && nums[middle] == nums[middle + 1])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return ans;
}


int findPeakElement(vector<int>& nums)
{
	int lo = 0, hi = nums.size() - 1;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if((mid == 0 || nums[mid] > nums[mid - 1]) 
		   && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
			return mid;
		else if(nums[mid] < nums[mid + 1])
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return -1;
}
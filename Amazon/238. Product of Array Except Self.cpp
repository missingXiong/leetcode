


vector<int> productExceptSelf(vector<int>& nums)
{
	int size = nums.size();
	if(nums.size() == 0) return {};
	vector<int> ans(size);
	// compute prefix product
	ans[0] = nums[0];
	for(int i = 1; i < size; i++)
		ans[i] = ans[i - 1] * nums[i];
	
	ans[size - 1] = ans[size - 2];
	int suffix = nums[size - 1];
	for(int i = size - 2; i >= 0; i--)
	{
		ans[i] = suffix * (i > 0 ? ans[i - 1] : 1);
		suffix = suffix * nums[i];
	}
		
	return ans;
}

// two pass
vector<int> productExceptSelf(vector<int>& nums)
{
	int size = nums.size();
	if(nums.size() == 0) return {};
	vector<int> ans(size);
	
	// compute prefix product exclude current element
	ans[0] = 1;
	for(int i = 1; i < size; i++)
		ans[i] = ans[i - 1] * nums[i - 1];
	
	int right = 1;
	for(int i = size - 1; i >= 0; i--)
	{
		ans[i] = ans[i] * right;
		right = right * nums[i];
	}
	return ans;
}

// one pass
vector<int> productExceptSelf(vector<int>& nums)
{
	int size = nums.size();
	if(nums.size() == 0) return {};
	vector<int> ans(size, 1);
	
	int from_first = 1, from_last = 1;
	for(int i = 0; i < size; i++)
	{
		ans[i] = ans[i] * from_first;
		from_first = from_first * nums[i];
		
		ans[size - i - 1] = ans[size - i - 1] * from_last;
		from_last = from_last * nums[size - i - 1];
	}
	return ans;
}


























bool checkSubarraySum(vector<int>& nums, int k)
{
	int size = nums.size();
	if (size == 0) return false;
	vector<int> prefix(size + 1, 0); // the sum of the first i elements(not include i)
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += nums[i];
		prefix[i + 1] = sum;
		for (int j = 0; j < i; j++)
		{
			int diff = sum - prefix[j];
			// diff == nk (if n == 0, diff shuold be 0; if k == 0, diff also should be 0)
			if (diff != 0 && k != 0 && diff % k == 0 || diff == 0)
				return true;
		}
	}
	return false;
}

// mod % k
bool checkSubarraySum(vector<int>& nums, int k)
{
	int size = nums.size();
	if (size == 0) return false;
	// edge case : {0, 0} ,k = 0
	unordered_map<int, int> modk_map = {{0, -1}};   // <prefix % k, the first time appears prefix % k>
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += nums[i];
		int val = k == 0 ? sum : sum % k;    // important
		if (modk_map.count(val) && i - modk_map[val] > 1)
			return true;
		else
			modk_map[val] = i;
	}
	return false;
}
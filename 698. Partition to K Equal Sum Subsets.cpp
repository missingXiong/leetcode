bool findSubset(int start, vector<int>& nums, vector<bool>& visited, int curr_sum, int target, int k)
{
	if (k == 1)
		return true;

	if (curr_sum == target)
		return findSubset(0, nums, visited, 0, target, k - 1);

	for (int i = start; i < nums.size(); i++)
	{
		if (visited[i] || curr_sum + nums[i] > target) continue;
		visited[i] = true;
		if (findSubset(i + 1, nums, visited, curr_sum + nums[i], target, k)) return true;
		visited[i] = false;
	}

	return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % k != 0) return false; 
	int target = sum / k;
	int size = nums.size();
	vector<bool> visited(size, false);
	// sort(nums.begin(), nums.end(), greater<int>());  // speedup

	return findSubset(0, nums, visited, 0, target, k);
}
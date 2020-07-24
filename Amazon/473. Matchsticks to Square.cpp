
// TLE
bool makesquare(vector<int>& nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum % 4 != 0  || nums.size() < 4) return false;
	
	int target = sum / 4;
	sort(nums.begin(), nums.end());
	
	vector<bool> used(nums.size(), false);
	return DFS(nums, used, target, 0, 4);
}

bool DFS(vector<int>& nums, vector<bool>& used, int target, int curr_sum, int k)
{
	if(k == 0) return true;
	
	if(target == curr_sum)
		return DFS(nums, used, target, 0, k - 1);
	
	for(int i = 0; i < nums.size(); i++)
	{
		if(used[i] || curr_sum + nums[i] > target) continue;
		used[i] = true;
		if(DFS(nums, used, target, curr_sum + nums[i], k)) return true;
		used[i] = false;
	}
	return false;
}

bool makesquare(vector<int>& nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum % 4 != 0  || nums.size() < 4) return false;
	
	int target = sum / 4;
	sort(nums.begin(), nums.end(), greater<int>());
	
	vector<int> sums(4, 0);
	return DFS(nums, sums, 0, target);
}

bool DFS(vector<int>& nums, vector<int>& sums, int index, int target)
{
	if(index == nums.size()) return true;
	
	for(int i = 0; i < 4; i++)
	{
		// pruning   
		if(sums[i] + nums[index] > target || (i > 0 && sums[i - 1] == sums[i])) continue;
		sums[i] += nums[index];
		if(DFS(nums, sums, index + 1, target)) return true;
		sums[i] -= nums[index];
	}
	return false;
}


698. Partition to K Equal Sum Subsets
bool canPartitionKSubsets(vector<int>& nums, int k)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum % k != 0  || nums.size() < k) return false; 
	
	sort(nums.begin(), nums.end(), greater<int>());
	int target = sum / k;
	vector<bool> used(nums.size(), false);
	return DFS(nums, used, target, 0, k);
}

bool DFS(vector<int>& nums, vector<bool>& used, int target, int curr_sum, int k)
{
	if(k == 0) return true;
	
	if(target == curr_sum)
		return DFS(nums, used, target, 0, k - 1);
	
	for(int i = 0; i < nums.size(); i++)
	{
		if(used[i] || curr_sum + nums[i] > target) continue;
		used[i] = true;
		if(DFS(nums, used, target, curr_sum + nums[i], k)) return true;
		used[i] = false;
	}
	return false;
}
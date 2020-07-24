

vector<vector<int>> threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	int size = nums.size();
	for(int i = 0; i < size - 2; i++)
	{
		if(i > 0 && nums[i] == nums[i - 1]) continue;
		
		int left = i + 1;
		int right = size - 1;
		while(left < right)
		{
			if(nums[left] + nums[right] == -nums[i])
			{
				ans.push_back({nums[i], nums[left], nums[right]});
				int l = nums[left], r = nums[right];
				
				// left < right is very important
				while(left < right && nums[left] == l) left++;
				while(left < right && nums[right] == r) right--;
			}
			else if(nums[left] + nums[right] < -nums[i])
				left++;
			else right--;
		}
	}
	return ans;
}

// TLE
void DFS(vector<int>& nums, int depth, int target, int start, vector<int>& curr, vector<vector<int>>& ans)
{
	if(depth == 3 && target == 0)
	{
		ans.push_back(curr);
		return;
	}
	
	for(int i = start; i < nums.size(); i++)
	{
		if(i > start && nums[i] == nums[i - 1]) continue;
		if(nums[i] > target) return;
		
		curr.push_back(nums[i]);
		DFS(nums, depth + 1, target - nums[i], i + 1, curr, ans);
		curr.pop_back();
	}
}

vector<vector<int>> threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	vector<int> curr;
	DFS(nums, 0, 0, 0, curr, ans);
	return ans;
}
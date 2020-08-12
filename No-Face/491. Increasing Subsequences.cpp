vector<vector<int>> findSubsequences(vector<int>& nums)
{
	vector<int> curr;
	vector<vector<int>> ans;
	dfs(nums, 0, curr, ans);
	return ans;
}

void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans)
{
    if (curr.size() > 1) ans.push_back(curr);
	if (start == nums.size()) return;
	
    unordered_set<int> used;
	for (int i = start; i < nums.size(); i++)
	{
		if ((curr.empty() || nums[i] >= curr.back()) && !used.count(nums[i]))
        {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, ans);
            curr.pop_back();
            used.insert(nums[i]);
        }
	}
}
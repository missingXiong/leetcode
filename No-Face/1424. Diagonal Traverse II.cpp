vector<int> findDiagonalOrder(vector<vector<int>>& nums)
{
	vector<int> ans;
	vector<vector<int>> dict;
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = 0; j < nums[i].size(); j++)
		{
			if(i + j == dict.size()) dict.push_back({});
			dict[i + j].push_back(nums[i][j]);
		}
	}
	
	for(vector<int>& v : dict)
	{
		std::reverse(v.begin(), v.end());
		ans.insert(ans.end(), v.begin(), v.end());
	}
	return ans;
}
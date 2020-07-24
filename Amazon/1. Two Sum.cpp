/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/


vector<int> twoSum(vector<int>&nums, int target)
{
	vector<int> ans;
	unordered_map<int, int> map;
	for(int i = 0; i < nums.size(); i++)
	{
		if(map.count(target - nums[i]))
		{
			ans.push_back(map[target - nums[i]]);
			ans.push_back(i);
		}
		else
			map[nums[i]] = i;
	}
	return ans;
}
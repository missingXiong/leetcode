
vector<int> nextGreaterElements(vector<int>& nums)
{
	int size = nums.size();
	int total = 2 * size;
	stack<int> stk;
	vector<int> ans(size);
	// 2 cycles
	for (int i = total - 1; i >= 0; i--)
	{
		while (!stk.empty() && nums[i % size] >= stk.top())
			stk.pop();
		ans[i % size] = stk.empty() ? -1 : stk.top();
		stk.push(nums[i % size]);
	}
	return ans;
}

556. Next Greater Element III
int nextGreaterElement(int n)
{
	string num = to_string(n);
	int len = num.length();
	
	int i = len - 2;
	for(; i >= 0; i--)
		if(num[i] < num[i + 1]) break;
	if(i < 0) return -1;
	
	for(int j = len - 1; j >= 0; j--)
	{
		if(num[j] > num[i])
		{
			swap(num[j], num[i]); 
			break;
		}
	}
	
	sort(num.begin() + i + 1, num.end());
	long res = stol(num);
	return res > INT_MAX ? -1 : res;
}


496. Next Greater Element I(monotonic stack)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
	if(nums1.size() == 0 || nums2.size() == 0) return {};
	
	stack<int> monoStk;
	unordered_map<int, int> m;
	for(int i = nums2.size() - 1; i >= 0; i--)
	{
		while(!monoStk.empty() && nums2[i] >= monoStk.top()) monoStk.pop();
		m[nums2[i]] = monoStk.empty() ? -1 : monoStk.top();
		monoStk.push(nums2[i]);
	}
	
	vector<int> ans;
	for(int num : nums1)
		ans.push_back(m[num]);
	return ans;
}

503. Next Greater Element II(monotonic stack)
// nums is a cycle array
vector<int> nextGreaterElements(vector<int>& nums)
{
	int size = nums.size();
	if(size == 0) return {};
	
	vector<int> ans(size, -1);
	stack<int> monoStk;
	for(int i = 2 * size - 1; i >= 0; i--)
	{
		while(!monoStk.empty() && nums[i % size] >= monoStk.top()) monoStk.pop();
		ans[i % size] = monoStk.empty() ? -1 : monoStk.top();
		monoStk.push(nums[i % size]);
	}
	return ans;
}

// monotonic deque
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> ans;
	deque<int> dq;
	for(int i = 0; i < nums.size(); i++)
	{
		while(!dq.empty() && dq.front() < nums[i]) dq.pop_front();
		dq.push_front(nums[i]);
		
		if(i + 1 - k >= 0)
		{
			ans.push_back(dq.back());
			if(dq.back() == nums[i + 1 - k]) dq.pop_back();
		}
	}
	return ans;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	multiset<int> ms;
	vector<int> ans;
	for(int i = 0; i < nums.size(); i++)
	{
		ms.insert(nums[i]);
		if(i + 1 - k >= 0)
		{
			ans.push_back(*ms.rbegin());
			ms.erase(ms.equal_range(nums[i + 1 - k]).first);
		}	
	}
	return ans;
}


480. Sliding Window Median
/*
295. Find Median from Data Stream没有固定计算长度
而此题把计算长度固定在Ｋ
*/
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
	multiset<double> ms;
	vector<double> ans;
	for(int i = 0; i < nums.size(); i++)
	{
		ms.insert(nums[i]);
		if(i + 1 - k >= 0)
		{
			vector<double> temp(ms.begin(), ms.end());
			ans.push_back((temp[k / 2] + temp[(k - 1) / 2]) / 2.0);
			ms.erase(ms.equal_range(nums[i + 1 - k]).first);
		}
	}
	return ans;
}

// 改进：keep track of middle iterator
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
	vector<double> ans;
	multiset<int> ms(nums.begin(), nums.begin() + k);
	auto middle = std::next(ms.begin(), k / 2);
	for(int i = k; i <= nums.size(); i++)
	{
		ans.push_back((double(*middle) + *prev(middle, 1 - k % 2)) / 2.0);
		if(i == nums.size())
			return ans;
		
		ms.insert(nums[i]);
		if(nums[i] < *middle)
			middle--;
		
		if(nums[i - k] <= *middle)
			middle++;
		ms.erase(ms.equal_range(nums[i - k]).first);
	}
	return ans;
}
































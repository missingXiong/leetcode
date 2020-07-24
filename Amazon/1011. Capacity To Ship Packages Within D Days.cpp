

please see the post: How to figure out that binary search would be applied here?
int shipWithinDays(vector<int>& weights, int D)
{
	int low = *max_element(weights.begin(), weights.end());
	int high = accumulate(weights.begin(), weights.end(), 0);
	int ans = -1;
	while(low <= high)
	{
		int capacity = low + (high - low) / 2;
		int day = calculate_day_to_ship(weights, capacity);
		if(day > D) low = capacity + 1;
		else 
		{
			ans = capacity;
			high = capacity - 1;
		}
	}
	return ans;
}

int calculate_day_to_ship(vector<int>& weights, int capacity)
{
	int day = 1, curr_sum = 0, i = 0;
	for(int i = 0; i < weights.size(); i++)
	{
		curr_sum += weights[i];
		if(curr_sum > capacity)
		{
			day++;
			curr_sum = weights[i];
		}
	}
	return day;
}

int search(int low, int high) 
{
	int ans = -1;
	while (low <= high) 
	{
		int mid = low + (high - low) / 2;
		if (judge(mid)) 
		{
			ans = mid;
			high = mid - 1;
		} 
		else low = mid + 1;
	}
	return ans;
}

410. Split Array Largest Sum
int splitArray(vector<int>& nums, int m)
{
	int maxVal = 0; 
    long sum = 0;
	for(int num : nums)
	{
		sum += num;
		maxVal = max(maxVal, num);
	}
	
	int ans = -1;
	long low = maxVal, high = sum;
	while(low <= high)
	{
		long value = low + (high - low) / 2;
		int parts = splitNumber(nums, value);
		if(parts <= m)
		{
			ans = value;
			high = value - 1;
		}
		else
			low = value + 1;
	}
	return ans;
}

int splitNumber(vector<int>& nums, long value)
{
	int parts = 1;
    long curr_sum = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		curr_sum += nums[i];
		if(curr_sum > value)
		{
			parts++;
			curr_sum = nums[i];
		}
	}
	return parts;
}


























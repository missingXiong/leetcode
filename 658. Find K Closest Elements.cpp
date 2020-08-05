
// O(nlogk)
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
	auto cmp = [&arr](const int lhi, const int rhi)
				{
					if(abs(arr[lhi] - x) != abs(arr[rhi] - x))
						return abs(arr[lhi] - x) < abs(arr[rhi] - x);
					else
						return arr[lhi] < arr[rhi];
				};
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);   // index
	
	for (int i = 0; i < arr.size(); i++)
	{
		pq.push(i);
		if(pq.size() > k) pq.pop();  // O(logk)
	}
	
	vector<int> ans;
	while(!pq.empty())
	{
		ans.push_back(arr[pq.top()]);
		pq.pop();
	}
	
	std::sort(ans.begin(), ans.end()); // O(klogk)
	return ans;
}

int findFirstGreaterIndex(vector<int>& arr, int target)
{
	int low = 0, high = arr.size() - 1;
	int index = arr.size();   // if index == -1, elements in arr are all less than x
	while (low <= high)
	{
		int middle = low + (high - low) / 2;
		if (arr[middle] > target)
		{
			index = middle;
			high = middle - 1;
		}
		else
			low = middle + 1;
	}
	return index;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
	int size = arr.size();
	int index = findFirstGreaterIndex(arr, x);
	int left = index - 1, right = index;
	vector<int> ans;
	/*
	while ((left >= 0 || right < size) && k-- > 0)
	{
		if (left < 0)  // move right
		{
			ans.push_back(arr[right++]);
		}
		else if (right >= size)  // move left
		{
			arr.push_back(arr[left--]);
		}
		else
		{
			if (abs(arr[left] - x) <= abs(arr[right] - x))
				arr.push_back(arr[left--]);
			else
				arr.push_back(arr[right++]);
		}
	}
	*/
	// simplify 
	while (k-- > 0)
	{
		if (right >= size || (left >= 0 && abs(arr[left] - x) <= abs(arr[right] - x)))
			ans.push_back(arr[left--]);
		else
			ans.push_back(arr[right++]);
	}
	
	
	sort(ans.begin(), ans.end());
	return ans;
}

// using std
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
	auto right = upper_bound(arr.begin(), arr.end(), x);
	auto left = right - 1;
	
	while (k-- > 0)
	{
		if (right == arr.end() || (left >= arr.begin()) && abs(*left - x) <= abs(*right - x))
			left--;
		else
			right++;
	}
	
	return vector<int>(left + 1, right);   // vector constructor
}



























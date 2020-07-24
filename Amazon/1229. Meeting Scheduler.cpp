
56. Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	if(intervals.size() == 0) return {};
	sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>&r)
		 {return l[0] < r[0];});
	vector<vector<int>> ans;
	ans.push_back(intervals[0]);
	for(int i = 1; i < intervals.size(); i++)
	{
		if(ans.back()[1] >= intervals[i][0])
			ans.back()[1] = max(ans.back()[1], intervals[i][1]);
		else
			ans.push_back(intervals[i]);
	}
	return ans;
}

1229. Meeting Scheduler
vector<int> minAvailableDuration(vector<vector<int>>& slots1, 
								 vector<vector<int>>& slots2, int duration)
{
	sort(slots1.begin(), slots1.end(),[](const vector<int>& l, const vector<int>& r)
										{return l[0] < r[0];});
	sort(slots2.begin(), slots2.end(),[](const vector<int>& l, const vector<int>& r)
	 									{return l[0] < r[0];});
	int i = 0, j = 0;
	while(i < slots1.size() && j < slots2.size())
	{
		int low = max(slots1[i][0], slots2[j][0]);
		int high = min(slots1[i][1], slots2[j][1]);
		if(high - low >= duration)
			return {low, low + duration};
		else
		{
			if(slots1[i][1] == high) i++;
			if(slots2[j][1] == high) j++;
		}
	}
	return {};
}
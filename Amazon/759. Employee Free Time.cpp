
// priority_queue  O(nlogn)
vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
{
	// minHeap
	auto cmp = [](const Interval& lhs, const Interval& rhs)
		{return lhs.start == rhs.start ? lhs.end > rhs.end : lhs.start > rhs.start;};
	priority_queue<Interval, vector<Interval>, decltype(cmp)> minHeap(cmp);
	
	for(auto group : schedule)
		for(auto range : group)
			minHeap.push(range);
	
	vector<Interval> ans;
	Interval current = minHeap.top(); minHeap.pop();
	while(!minHeap.empty())
	{
		Interval temp = minHeap.top(); minHeap.pop();
		if(current.end > temp.start)
			current.end = max(current.end, temp.end);
		else
		{
			ans.push_back(Interval(current.end, temp.start));
			current = temp;
		}
	}
	return ans;
}

vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
{
	vector<pair<int, int>> points;
	for(auto employee : schedule)
	{
		for(auto time : employee)
		{
			points.emplace_back(time.start, 1);
			points.emplace_back(time.end, -1);
		}
	}
	
	sort(points.begin(), points.end());
	
	int cnt = 0;
	vector<Interval> ans;
	for(int i = 0; i < points.size(); i++)
	{
		if(i > 0 && cnt == 0 && (points[i - 1].first != points[i].first))
			ans.push_back(Interval(points[i - 1].first, points[i].first));
		cnt += points[i].second;
	}
	return ans;
}

vector<Interval> employeeFreeTime(vector<vector<Interval>>& a) 
{
	vector<Interval> res;
	map<int, int> timeline;
	for (auto &v : a) 
	{
		for (auto &i : v) 
		{
			timeline[i.start]++;
			timeline[i.end]--;
		}
	}
	int overlap = 0;
	for (auto it1 = timeline.begin(); it1 != timeline.end(); it1++) 
	{
		overlap += it1->second;
		auto it2 = next(it1, 1);
		if (it2 == timeline.end()) break;
		if (!overlap) res.emplace_back(it1->first, it2->first);
	}
	return res;
}

// time complexity: O(nlogk)
// like merge K sorted list
vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) 
{
	auto cmp = [](const auto& lhs, const auto& rhs) {return lhs[2] > rhs[2];};
	priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
	for(int i = 0; i < schedule.size(); i++)
		minHeap.push(vector<int>{i, 0, schedule[i][0].start});   // <which employee, which time span, start point>
	
	vector<Interval> ans;
	int preEnd = -1, preStart;    // previous end value
	while(!minHeap.empty())
	{
		auto point = minHeap.top(); minHeap.pop();
		Interval curr = schedule[point[0]][point[1]];
		if(preEnd >= point[2])  // has overlap
			preEnd = max(preEnd, curr.end);
		else  // no overlap
		{
			if(preEnd != -1) ans.push_back(Interval(preEnd, curr.start));
			preStart = curr.start;
			preEnd = curr.end;
		}
		
		if(point[1] < schedule[point[0]].size() - 1)
			minHeap.push(vector<int>{point[0], point[1] + 1, schedule[point[0]][point[1] + 1].start});
	}
	return ans;
}


























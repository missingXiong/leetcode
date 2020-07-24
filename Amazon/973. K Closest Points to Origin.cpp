

vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
{
	auto cmp = [](const pair<int, int> l, const pair<int, int> r)
					{ return sqrt(l.first * l.first + l.second * l.second)
						< sqrt(r.first * r.first + r.second * r.second); };
	priority_queue<pair<int ,int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
	for(vector<int>& p : points)
	{
		maxHeap.emplace(p[0], p[1]);
		if(maxHeap.size() > K) maxHeap.pop();
	}
	
	vector<vector<int>> ans;
	while(!maxHeap.empty())
	{
		ans.push_back({maxHeap.top().first, maxHeap.top().second});
		maxHeap.pop();
	}
	return ans;
}
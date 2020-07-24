

vector<int> topKFrequent(vector<int>& nums, int k)
{
	unordered_map<int, int> counts;
	for(int num : nums)
		counts[num]++;
	
	auto compare = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
					  {return lhs.second > rhs.second;};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
	for(auto& p : counts)
	{
		pq.push(p);
		if(pq.size() > k) pq.pop();
	}
	
	vector<int> ans;
	while(!pq.empty())
	{
		ans.push_back({pq.top().first});
		pq.pop();
	}
	return ans;
}
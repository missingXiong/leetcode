
// multiset
vector<string> topKFrequent(vector<string>& words, int k)
{
	unordered_map<string, int> counts;
	for(const string& s : words)
		counts[s]++;
	
	auto compare = [](pair<string, int>& lhs, pair<string, int>& rhs)
					{
						if(lhs.second == rhs.second)
							return lhs.first < rhs.first;
						else
							return lhs.second > rhs.second;
					};
	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> pq(compare);
	
	for(auto p : counts)
	{
		pq.emplace(p.first, p.second);
		if(pq.size() > k) pq.pop();
	}
	
	vector<string> ans;
	while(!pq.empty())
	{
		ans.push_back(pq.top().first);
		pq.pop();
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}
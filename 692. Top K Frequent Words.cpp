vector<string> topKFrequent(vector<string>& words, int k)
{
        	unordered_map<string, int> count;
	for(string word : words) count[word]++;
	
	auto cmp = [](const pair<string, int>& lhp, const pair<string, int>& rhp)
					{
						if(lhp.second != rhp.second)
							return lhp.second > rhp.second;
						else
							return lhp.first < rhp.first;
					};
	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
	
	for(auto& p : count)
	{
		pq.push(p);
		if(pq.size() > k) pq.pop();
	}
	
	vector<string> ans;
	while(!pq.empty())
	{
		ans.push_back(pq.top().first);
		pq.pop();
	}
	
	reverse(ans.begin(), ans.end());   // need reverse
	return ans;
}
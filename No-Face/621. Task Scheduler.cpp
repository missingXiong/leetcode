int leastInterval(vector<char>& tasks, int n)
{
	int size = tasks.size();
	if (n == 0)  return size;
	
	unordered_map<char, pair<int, int>> cache;  // waiting list :<task name, <wait, task remain>>
	unordered_map<char, int> cnt;
	for (char c : tasks) cnt[c]++;
	
	auto cmp = [](const pair<char, int> lhp, const pair<char, int> rhp) { return lhp.second < rhp.second; };
	priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
	for (auto p : cnt) pq.emplace(p);
	
	int count = 0;
	while (size)
	{
		count++;
		
		// change cache
		for (auto& p : cache)
			p.second.first--;
		
		if (!pq.empty())
		{
			size--;
			char c = pq.top().first;
			int times = pq.top().second;
			pq.pop();
			if (--times > 0)
				cache[c] = {n, times};
		}
		
		for (auto& p : cache)
		{
			if (p.second.first == 0)
				pq.emplace(p.first, p.second.second);
		}
	}
	
	return count;
}
// unordered_map can be replaced by vector: only 26 characters
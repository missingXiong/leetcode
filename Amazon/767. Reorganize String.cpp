
// time complexity: O(n)
string reorganizeString(string S)
{
	if(S.length() == 0) return "";
	
	unordered_map<char, int> counts;
	for(const char c : S) counts[c]++;
	auto cmp = [](const pair<int, char>& lhs, const pair<int, char>& rhs)
					{ return lhs.first < rhs.first; };
	priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> pq(cmp);
	for(auto p : counts)
		pq.emplace(p.second, p.first);
	
	string ans;
	char pre = '';
	vector<pair<int, char>> vp;
	while(!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		if(p.second == pre)
			vp.push_back(p);
		else
		{
			ans.push_back(p.second);
			if(--p.first > 0) 
				pq.emplace(p.first, p.second);
			for(auto pi : vp)
				pq.emplace(pi);
			vp.clear();
		}
	}
	
	return vp.empty() ? ans : "";
}


// time complexity: O(n)
string reorganizeString(string S)
{
	int len = S.length();
	unordered_map<char, int> counts;
	for(const char c : S) counts[c]++;
	vector<pair<int, char>> charCounts;
	for(auto p : counts)
	{
		if(p.second > (size - 1) / 2 + 1) return "";
		charCounts.emplace_back(p.second, p.first);
	}
		
	sort(charCounts.begin(), charCounts.end(), 
		[](const auto& lp, const auto& rp) {return lp.first > rp.first;});
	
	// copy string
	
	// insertion
}






















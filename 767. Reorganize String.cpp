typedef tuple<char, int, int> tp;
string reorganizeString(string S)
{
	auto cmp = [](const pair<char, int> lhp, const pair<char, int> rhp) { return lhp.second < rhp.second; };
	priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
		
	unordered_map<char, int> count;
	for(char c : S)
		if(++count[c] > (S.length() + 1) / 2) return "";
	
	for(auto p : count)
		pq.push(p);
	
	string ans = "";
	pair<char, int> prev = make_pair('a', 0);
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		ans.push_back(cur.first);
		
		if(prev.second > 0)
			pq.push(prev);
		prev = make_pair(cur.first, cur.second - 1);	
	}
	
	return ans;
}
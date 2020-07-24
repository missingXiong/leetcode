

vector<string> findItinerary(vector<vector<string>>& tickets)
{
	unordered_map<string, vector<string>> graph;
	for(vector<string>& ticket : tickets)
		graph[ticket[0]].push_back(ticket[1]);
	
	for(auto& p : graph)
	{
		auto& dests = p.second;
		sort(dests.begin(), dests.end(),
			[](const string& lhs, const string& rhs) {return lhs > rhs;});
	}
	
	vector<string> ans;
	DFS(graph, "JFK", ans);
	reverse(ans.begin(), ans.end());
	return ans;
}

void DFS(unordered_map<string, vector<string>>& graph, string src, vector<string>& ans)
{
	if(graph[src].empty())
	{
		ans.push_back(src);
		return;
	}
	
	auto& dests = graph[src];  
	// 访问当前节点的所有子节点
	while(!dests.empty())
	{
		string city = dests.back();
		dests.pop_back();    // 每次访问子节点，都要删除对应边
		DFS(graph, city, ans);
	}
	ans.push_back(src);
}
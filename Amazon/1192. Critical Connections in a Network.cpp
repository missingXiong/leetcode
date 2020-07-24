
// tarjan隔点算法求割点（articulation point）与桥
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{
	int time = 0;
	vector<int> disc(n, 0);
	vector<int> low(n, 0);
	vector<int> parent(n, -1);
	vector<vector<int>> ans;
	
	unordered_map<int, vector<int>> graph;
	for(vector<int> edge : connections)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	for(int v = 0; v < n; v++)
	{
		if(disc[v] == 0)
			DFS(v, time, graph, disc, low, parent, ans);
	}
	return ans;
}

void DFS(int v, int time, unordered_map<int, vector<int>>& graph,
		 vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& ans)
{
	disc[v] = low[v] = ++time;
	for(int u : graph[v])
	{
		if(disc[u] == 0)
		{
			parent[u] = v;
			DFS(u, time, graph, disc, low, parent, ans);
			low[v] = min(low[v], low[u]);
			
			if(low[u] > disc[v])
				ans.push_back({u, v});
		}
		else if(parent[v] != u)
			low[v] = min(low[v], disc[u]);
	}
}



































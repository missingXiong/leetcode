vector<vector<int>> graph;
vector<int> disc;    // record the first time visit nodes
vector<int> low;     // how far the node can reach
vector<int> parent;
int timestamp;
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{
	timestamp = 0;      
	disc = vector<int>(n, -1);
	low = vector<int>(n, -1);
	parent = vector<int>(n, -1);
	graph = vector<vector<int>>(n);
	
	for (auto& edge : connections)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}

	vector<vector<int>> bridge;
	for (int u = 0; u < n; u++)
	{
		if (disc[u] == -1)   // unvisit
			dfs(u, bridge);
	}
	
	return bridge;
}

void dfs(int from, vector<vector<int>>& bridge)
{
	disc[from] = low[from] = timestamp++;
	for (int to : graph[from])
	{
		if (parent[from] == to) continue;  // not visit its parent node
		if (disc[to] == -1)   // unvisit : forward edge
		{
			parent[to] = from;
			dfs(to, bridge);
			low[from] = min(low[from], low[to]);
			
			if (low[to] > disc[from])
				bridge.push_back({from, to});
		}
		else    // visited : back edge
			low[from] = min(low[from], disc[to]);
	}
}

// alternate function
void dfs(int from, vector<vector<int>>& bridge)
{
	disc[from] = low[from] = timestamp++;
	for (int to : graph[from])
	{
		if (disc[to] == -1)   // unvisit : forward edge
		{
			parent[to] = from;
			dfs(to, bridge);
			low[from] = min(low[from], low[to]);
			
			if (low[to] > disc[from])
				bridge.push_back({from, to});
		}
		else if (parent[from] != to)   // visited : back edge
			low[from] = min(low[from], disc[to]);   // or low[v] = min(low[v], low[u]);
	}
}


















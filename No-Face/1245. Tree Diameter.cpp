
/*
int treeDiameter(vector<vector<int>>& edges)
{
	unordered_map<int, vector<int>> graph;
	unordered_set<int> nodes;
	for (auto edge : edges)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
		nodes.insert(edge[0]);
		nodes.insert(edge[1]);
	}
	
	int ans = 0;
	for(int v : nodes)
	{
		unordered_set<int> visited;
		visited.insert(v);
		backtracking(graph, visited, v, 0, ans);
	}
	
	return ans;
}


void backtracking(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int v, int length, int& ans)
{
	for(int u : graph[v])
	{
		if(visited.find(u) == visited.end())
		{
			visited.insert(u);
			backtracking(graph, visited, u, length + 1, ans);
		}
	}
	
	ans = max(ans, length);
}
*/

int treeDiameter(vector<vector<int>>& edges)
{
	unordered_map<int, vector<int>> graph;
	for (auto edge : edges)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	int ans = 0, next = -1, maxlen = 0;
	vector<bool> visited(edges.size() + 1, false);
	visited[0] = true;
	backtracking(graph, visited, 0, 0, maxlen, next);
	
	maxlen = 0;
	visited.assign(edges.size() + 1, false);
	visited[next] = true;
	backtracking(graph, visited, next, 0, maxlen, next);
	
	return maxlen;
}

void backtracking(unordered_map<int, vector<int>>& graph, vector<bool>& visited, int v, int length, int& maxlen, int& next)
{
	for(int u : graph[v])
	{
		if(!visited[u])
		{
			visited[u] = true;
			backtracking(graph, visited, u, length + 1, maxlen, next);
		}
	}
	
	if(length > maxlen)
	{
		next = v;
		maxlen = length;
	}
}













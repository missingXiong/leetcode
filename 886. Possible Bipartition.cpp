
// dfs
bool dfs(int v, int color, vector<vector<int>>& graph, vector<int>& colors)
{
	if(colors[v] != 0) return colors[v] == color;   // already colored
	
	colors[v] = color;
	for(int u : graph[v])
	{
		int c = color == 1 ? 2 : 1;
		if(!dfs(u, c, graph, colors)) return false;
	}
	
	return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes)
{
	vector<int> colors(N + 1, 0);   // color: 1 && 2
	vector<vector<int>> graph(N + 1);
	for(vector<int> edge : dislikes)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	for(int v = 1; v <= N; v++)
	{
		if(colors[v] == 0)  // not visit yet
		{
			if(!dfs(v, 1, graph, colors)) return false;
		}
	}
	return true;
}

// bfs
bool possibleBipartition(int N, vector<vector<int>>& dislikes)
{
	vector<int> colors(N + 1, 0);   // color: 1 && 2
	vector<vector<int>> graph(N + 1);
	for(vector<int> edge : dislikes)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	queue<int> q;
	for(int i = 1; i <= N; i++)
	{
		if(colors[i] != 0) continue;   // already colored
		
		queue.push(i);
		colors[i] = 1;
		while(!queue.empty())
		{
			int size = q.size();
			while(size--)
			{
				int curr = q.front(); q.pop();
				int c = colors[curr] == 1 ? 2 : 1;
				for(int v : graph[curr])
				{
					if(colors[v] == 0)
					{
						colors[v] = c;
						q.push(v);
					}
					else if(colors[v] != c)
						return false;
				}
			}
		}
	}
	
	return true;
}

// detect cycle which has odd nodes
bool possibleBipartition(int N, vector<vector<int>>& dislikes)
{
	vector<int> status(N + 1, 0);   // 0: unvisited 1: visiting 2: visited
	vector<vector<int>> graph(N + 1);
	for(vector<int> edge : dislikes)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	for(int v = 1; v <= N; v++)
	{
		if(status[v] == 0)
			if(dfs(v, 0, graph, status)) return false;
	}
	return true;
}


// detect cycle
bool dfs(int v, int length, vector<vector<int>>& graph, vector<int>& status)
{
	if(status[v] == 1)    // detect cycle
		return length % 2 == 0;
	if(status[v] == 2)    // already visited
		return false;
	
	// not visit yet
	status[v] = 1;
	for(int nbr : graph[v])
	{
		if(dfs(nbr, length + 1, graph, status)) return true;
	}
	status[v] = 2;
    
	return false;
}
























207. Course Schedule
// DFS
bool cycle_dfs(vector<vector<int>>& graph, vector<int>& status, int u)
{
	if(status[u] == 1) return true;
	if(status[u] == 2) return false;
	// visit all its neighbor
	status[u] = 1;
	for(int v : graph[u])
	{
		if(cycle_dfs(graph, status, v))
			return true;
	}
	status[u] = 2;
	return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<vector<int>> graph(numCourses);
	for(const vector<int> edge : prerequisites)
		graph[edge[1]].push_back(edge[0]);
	
	// status: unvisit => 0  visiting = > 1, visited => 2
	vector<int> status(numCourses, 0);
	for(int u = 0; u < numCourses; u++)
	{
		if(status[u] == 0)   // 要不要都无所谓
			if(cycle_dfs(graph, status, u)) return false;
	}
	return true;
}

// BFS
void buildGraph(vector<vector<int>>& prerequisites,
				vector<vector<int>>& graph, vector<int>& indegree)
{
	for(const vector<int>& edge : prerequisites)
	{
		graph[edge[1]].push_back(edge[0]);
		indegree[edge[0]]++;
	}
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<vector<int>> graph(numCourses);
	vector<int> indegree(numCourses, 0);
	buildGraph(prerequisites, graph, indegree);
	
	int cnt = 0;
	queue<int> q;
	for(int v = 0; v < numCourses; v++)
		if(indegree[v] == 0) q.push(v);
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		for(int u : graph[v])
		{
			if(--indegree[u] == 0)
				q.push(u);
		}
		cnt++;
	}
	
	return cnt == numCourses;
}

// find all topological order of a DAG
void backtracking(int vertices, vector<vector<int>>& graph, vector<vector<int>>& ans,
				  vector<int>& indegree, vector<bool>& visited, vector<int>& path)
{
	if(path.size() == vertices)
	{
		ans.push_back(path);
		return;
	}
	
	for(int v = 0; v < vertices; v++)
	{
		if(indegree[v] == 0 && !visited[v])  // important
		{
			for(int u : graph[v])
				indegree[u]--;
			path.push_back(v);
			visited[v] = true;
			
			backtracking(vertices, graph, ans, indegree, visited, path);
			
			for(int u : graph[v])
				indegree[u]++;
			path.pop_back();
			visited[v] = false;
		}	
	}
}

vector<vector<int>> findAllTopo(int vertices, vector<vector<int>>& graph)
{
	vector<int> indegree(vertices, 0);
	for(vector<int>& edge : graph)
		for(int v : edge)
			indegree[v]++;
	
	vector<bool> visited(vertices, false);
	vector<vector<int>> ans;
	vector<int> path;
	backtracking(vertices, graph, indegree, ans, visited, path);
	return ans;
}

210. Course Schedule II
void buildGraph(vector<vector<int>>& prerequisites,
				vector<vector<int>>& graph, vector<int>& indegree)
{
	for(const vector<int>& edge : prerequisites)
	{
		graph[edge[1]].push_back(edge[0]);
		indegree[edge[0]]++;
	}
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<int> ans;
	vector<vector<int>> graph(numCourses);
	vector<int> indegree(numCourses, 0);
	buildGraph(prerequisites, graph, indegree);
	
	int cnt = 0;
	queue<int> q;
	for(int v = 0; v < numCourses; v++)
		if(indegree[v] == 0) q.push(v);
		
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		ans.push_back(v);
		for(int u : graph[v])
		{
			if(--indegree[u] == 0)
				q.push(u);
		}
		cnt++;
	}
	
	return cnt == numCourses ? ans : vector<int>{};
}








































1. strongly connected components
2. bridge
3. articulation points


void DFS(int v, 
		 int time,
		 unordered_map<int, vector<int>>& graph,
		 vector<int>& disc,
		 vector<int>& low,
		 stack<int>& stk,
		 vector<bool>& stkMember,
		 vector<vector<int>>& SCC);
// Strongly Connected Components
vector<vector<int>> SCC(int n, vector<vector<int>> connections)
{
	vector<int> disc;   // the time when a node is visited 1st time while DFS traversal
	vector<int> low;    // the topmost reachable ancestor
	int time = 0;
	stack<int> stk;     // store SCC
	vector<bool> stkMember(n, false);   // check whether a node is in the stack
	vector<vector<int>> SCC;
	
	// initialization
	unordered_map<int, vector<int>> graph;
	for(const vector<int> e : connections)
	{
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}
	
	disc = vector<int>(n, 0);
	low = vector<int>(n, 0);
	
	for(int v = 0; v < n; v++)
	{
		if(disc[v] == 0) // unvisited
			DFS(v, time, graph, disc, low, stk, stkMember, SCC);
	}
	return SSC;
}

void DFS(int v, int time, unordered_map<int, vector<int>>& graph, vector<int>& disc,
		 vector<int>& low, stack<int>& stk, vector<bool>& stkMember, vector<vector<int>>& SCC)
{
	disc[v] = low[v] = ++time;
	stk.push(v);
	stkMember[v] = true;
	
	for(int u : graph[v])
	{
		if(disc[u] == 0)  // forward edge
		{
			DFS(u, time, graph, disc, low, stk, stkMember);
			low[v] = min(low[v], low[u]);
		}
		else if(stkMember[u] == true)   // back edge
			low[v] = min(low[v], disc[u]); // or low[v] = min(low[v], low[u]); 
	}
	
	// the vertex of SCC
	vector<int> component;
	if(disc[v] == low[v])
	{
		while(stk.top() != v)
		{
			component.push_back(stk.top());
			stkMember[stk.top()] = false; 
			stk.pop();
		}
		component.push_back(stk.top());
		stkMember[stk.top()] = false; 
		stk.pop();
	}
	
	SCC.push_back(component);
}

void DFS(int v, 
		 int time,
		 unordered_map<int, vector<int>>& graph,
		 vector<int>& disc,
		 vector<int>& low,
		 vector<int> parent,
		 unordered_set<int> ap);
// Articulation Points: a vertex removing which increases number of connected components
vector<int> AP(int n, vector<vector<int>> connections)
{
	vector<int> disc;   // the time when a node is visited 1st time while DFS traversal
	vector<int> low;    // the topmost reachable ancestor
	int time = 0;
	vector<int> parent;
	unordered_set<int> ap;
	
	// initialization
	unordered_map<int, vector<int>> graph;
	for(const vector<int> e : connections)
	{
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}
	
	disc = vector<int>(n, 0);
	low = vector<int>(n, 0);
	parent = vector<int>(n, -1);
	
	for(int v = 0; v < n; v++)
	{
		if(disc[v] == 0) // unvisited
			DFS(v, time, graph, disc, low, parent, ap);
	}
	
	vector<int> ans(ap.begin(), ap.end());
	return ans;
}

void DFS(int v, int time, unordered_map<int, vector<int>>& graph,
		 vector<int>& disc, vector<int>& low, vector<int>& parent, unordered_set<int>& ap);
{
	disc[v] = low[v] = ++time;
	int children = 0;
	for(int u : graph[v])    
	{
		if(disc[u] == 0)  // u是v的字节点
		{
			parent[u] = v; children++;
			DFS(u, time, graph, disc, low, parent, ap);
			low[v] = min(low[v], low[u]);
			
			if(parent[v] == -1 && children > 1)  // ap
				ap.insert(v);
			
			if(parent[v] != -1 && low[u] >= disc[v])  // ap
				ap.insert(v);
			
			if(low[u] > disc[v])  // bridge
				// addedge(u, v);
		}
		else if(parent[v] != u)
			low[v] = min(low[v], disc[u]); // or low[v] = min(low[v], low[u]);
	}
}


/************** Bridge ***************/
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
































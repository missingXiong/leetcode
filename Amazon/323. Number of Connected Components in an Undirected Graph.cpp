

int countComponents(int n, vector<vector<int>>& edges)
{
	vector<vector<int>> graph(n);
	for(auto edge : edges)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	int count = 0;
	vector<bool> visited(n, false);
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			count++;
			visited[i] = true;
			DFS(graph, visited, i);
		}
	}
	return count;
}

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int u)
{
	for(int v : graph[u])
	{
		if(!visited[v])
		{
			visited[v] = true;
			DFS(graph, visited, v);
		}
	}
}

class UnionFind
{
public:
	UnionFind(int n)
	{
		count = n;
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}
	
	int find(int x)
	{
		if(parent[x] == x) return parent[x];
		return parent[x] = find(parent[x]);
	}
	
	void connect(int x, int y)
	{
		int root_x = find(x);
		int root_y = find(y);
		if(root_x != root_y)
		{
			parent[root_x] = root_y;
			count--;
		}
	}
	
	int query() {return count;}
private:
	int count;
	vector<int> parent;
};

int countComponents(int n, vector<vector<int>>& edges)
{
	UnionFind uf(n);
	for(auto edge : edges)
		uf.connect(edge[0], edge[1]);
	return uf.query();
}

































5/24/2020
1192. Critical Connections in a Network
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{
	vector<vector<int>> graph(n);
	for(const vector<int>& edge : connections)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	
	vector<int> disc(n, 0);
	vector<int> low(n, 0);
	vector<int> parent(n, -1);
	vector<vector<int>> bridge;
	vector<int> points;
	
	for(int u = 0; u < n; u++)
		if(disc[u] == 0)
			DFS(graph, u, 0, disc, low, parent, bridge);
	return bridge;
}

void DFS(vector<vector<int>>& graph, int u, int time,
			vector<int>& disc,
			vector<int>& low,
			vector<int>& parent,
			vector<vector<int>>& bridge,
			vector<int>& points)
{
	disc[u] = low[u] = ++time;
	int children = 0;
	for(int v : graph[u])
	{
		if(disc[v] == 0)   // forward
		{
			children++;
			parent[v] = u;
			DFS(graph, v, time, disc, low, parent, bridge);
			low[u] = min(low[u], low[v]);
			
			if(parent[u] == -1 && children > 1)
				points.push_back(u);
			if(parent[u] != -1 && low[v] >= disc[u])
				points.push_back(u);
		
			// bridge
			if(low[v] > disc[u])
				bridge.push_back({u, v});
		}
		else if(parent[u] != v)    // backward
			low[u] = min(low[u], low[v]);
	}
}

class UnionFind
{
public:
	UnionFind(int n) 
	{
		for(int i = 0; i < n; i++)
			parent[i] = i;
		count = n;
	}
	
	int find(int x)
	{
		if(x == parent[x]) return parent[x];
		parent[x] = find(parent[x]);
		return parent[x];
	}
	
	void union(int x, int y)
	{
		int root_x = find(x);
		int root_y = find(y);
		if(root_x != root_y)
		{
			parent[root_x] = root_y;
			count--;
		}
	}
	
	bool connect(int x, int y)
	{
		return find(x) == find(y);
	}
	
	int query() {return this->count;}
private: 
	vector<int> parent;
	int count;
};

139. Word Break
bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	int len = s.length();
	vector<bool> dp(len + 1, false);
	dp[0] = true;
	for(int i = 1; i <= len; i++)
	{
		for(int j = 0; j < i; j++)
		{
			string right = s.substr(j, i - j);
			if(dp[j] && dict.count(right))
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[len];
}

bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	return search(dict, s);
}

unordered_map<string, bool> memo;
bool search(unordered_set<string>& dict, string& s)
{
	if(memo.count(s)) return memo[s];
	if(dict.count(s)) {memo[s] = true; return true;}
	
	for(int i = 1; i < s.length(); i++)
	{
		string left = s.substr(0, i);
		string right = s.substr(i);
		if(dict.count(left) && search(dict, right))
			return memo[s] = true;
	}
	return memo[s] = false;
}

140. Word Break II
vector<string> wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	return search(dict, s);
}

vector<string> append(string& s, vector<string>& vs)
{
	vector<string> ans;
	for(string& word : vs)
		ans.push_back(s + " " + word);
	return ans;
}

unordered_map<string, vector<string>> memo;
vector<string> search(unordered_set<string>& dict, string& s)
{
	if(memo.count(s)) return memo[s];
	
	vector<string> ans;
	if(dict.count(s))
		ans.push_back({s});
	for(int i = 1; i < s.lenght(); i++)
	{
		string left = s.substr(0, i);
		if(!dict.count(left)) continue;
		string right = s.substr(i);
		vector<string> rv = append(left, search(dict, right));
		ans.insert(ans.end(), rv.begin(), rv.end());
	}
	return memo[s] = ans;
}




































class UnionFind
{
	UnionFind(unordered_set<string>& dict) 
	{
		for (string& s : dict)
			parent[s] = s;
	}
	
	string find(string& s)
	{
		if (parent[s] == s) return s;
		return parent[s] = find(parent[s]);
	}
	
	void join(string& x, string& y)
	{
		string root_x = find(x);
		string root_y = find(y);
		if (root_x != root_y)
		{
			parent[root_x] = root_y;
		}
	}
	
private:
	unordered_map<string, string> parent;
};

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	int size = equations.size();
	unordered_map<string, unodered_map<string, double>> table;
	unordered_set<string> dict;
	for (int i = 0; i < size; i++)
	{
		dict.insert(equations[i][0]);
		dict.insert(equations[i][1]);
		table[equations[i][0]][equations[i][1]] = values[i];
		table[equations[i][1]][equations[i][0]] = 1.0 / values[i];
	}
	
	UnionFind uf(dict);
	for (auto& edge : equations)
	{
		uf.join(edge[0], edge[1]);
	}
	
	vector<souble> ans;
	for (auto& query : queries)
	{
		if (!table.count(query[0]) || !table.count(query[1]))
			ans.push_back(-1.0);
		else
		{
			string p1 = uf.find(query[0]);
			string p2 = uf.find(query[1]);
			if (p1 == p2)
			{
				ans.push_back(table[query[0]][p1] * table[p1][query[1]]);
			}
			else
				ans.push_back(-1.0);
		}
	}
	return ans;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	int size = equations.size();
	unordered_map<string, unordered_map<string, double>> table;
	for (int i = 0; i < size; i++)
	{
		table[equations[i][0]][equations[i][1]] = values[i];
		table[equations[i][1]][equations[i][0]] = 1.0 / values[i];
	}
	
	vector<double> ans;
	for (auto& query : queries)
	{
		if (!table.count(query[0]) || !table.count(query[1]))
			ans.push_back(-1.0);
		else if (query[0] == query[1])
			ans.push_back(1.0);
		else
		{
			unordered_set<string> visited;
			double val = dfs(table, query[0], query[1], visited);
			if (val) ans.push_back(val);
			else ans.push_back(-1.0);
		}
	}
	return ans;
}

double dfs(unordered_map<string, unordered_map<string, double>>& table, string u, string v, unordered_set<string>& visited)
{
	if (u == v) return 1.0;
	visited.insert(u);
	for (auto nbr : table[u])
	{
		if (visited.count(nbr.first)) continue;
		double val = dfs(table, nbr.first, v, visited);
		if (val) return val * nbr.second;
	}
	
	return 0.0;
}














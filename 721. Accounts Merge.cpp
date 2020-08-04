class UnionFind
{
public:
	UnionFind(int size) : count(size)
	{
		parent = vector<int>(count);
		for(int i = 0; i < count; i++)
			parent[i] = i;
	}
	
	int find(int x)
	{
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}
	
	void join(int x, int y)
	{
		int root_x = find(x);
		int root_y = find(y);
		
		if(root_x != root_y)
			parent[root_x] = root_y;
	}
	
private:
	int count;
	vector<int> parent;
};

// union find
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	int size = accounts.size();
	
	UnionFind uf(size);
	unordered_map<string, int> email_id;
	for(int i = 0; i < size; i++)
	{
		for(int j = 1; j < accounts[i].size(); j++)
		{
			// first time find accounts[i][j]
			if(email_id.find(accounts[i][j]) == email_id.end())
				email_id[accounts[i][j]] = i;
			else
			{
				// find accounts[i][j] again, so union 
				uf.join(email_id[accounts[i][j]], i);
				// can't update id in here, because other string's parent won't change
			}
		}
	}
	
	// this part is very important
	unordered_map<int, vector<string>> set_emails;
	for(const auto& p : email_id)
	{
		int parent = uf.find(p.second);
		set_emails[parent].push_back(p.first);
	}
	
	vector<vector<string>> res;
	for(auto& it : set_emails)
	{
		sort(it.second.begin(), it.second.end());
		vector<string> temp;
		temp.push_back(accounts[it.first][0]);
		temp.insert(temp.end(), it.second.begin(), it.second.end());
		res.push_back(temp);
	}
	
	return res;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	unordered_map<string, vector<string>> graph;
	for(int i = 0; i < accounts.size(); i++)
	{
		for(int j = 2; j < accounts[i].size(); j++)
		{
			graph[accounts[i][1]].push_back(accounts[i][j]);
			graph[accounts[i][j]].push_back(accounts[i][1]);
		}
	}
	
	unordered_set<string> visited;
	vector<vector<string>> ans;
	for(int i = 0; i < accounts.size(); i++)
	{
		vector<string> temp = {accounts[i][0]};
		set<string> set;
		for(int j = 1; j < accounts[i].size(); j++)
		{
			dfs(accounts[i][j], graph, set, visited);
		}
		
		if(!set.empty())  // ignore empty account
		{
			temp.insert(temp.end(), set.begin(), set.end());
			ans.push_back(temp);
		}
	}
	
	return ans;
}

void dfs(string curr, unordered_map<string, vector<string>>& graph, set<string>& set, unordered_set<string>& visited)
{
	if(visited.count(curr)) return;
	
	visited.insert(curr);
	set.insert(curr);
	for(string nxt : graph[curr])
	{
		dfs(nxt, graph, set, visited);
	}
}













































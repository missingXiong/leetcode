

// DFS 注意复习815
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	unordered_map<string, vector<int>> graph;   // <string, 集合>
	for(int i = 0; i < accounts.size(); i++)
	{
		for(int j = 1; j < accounts[i].size(); j++)
			graph[accounts[i][j]].push_back(i);
	}
	
	unordered_set<int> visited; // 有哪些集合已经被访问
	vector<vector<string>> res;
	for(int i = 0; i < accounts.size(); i++)
	{
		if(!visited.count(i))
		{
			visited.insert(i);
			unordered_set<string> merge(accounts[i].begin() + 1, accounts[i].end());
			search_DFS(accounts, graph, i, visited, merge);
            vector<string> ans;
            ans.push_back(accounts[i][0]);
            ans.insert(ans.end(), merge.begin(), merge.end());
            sort(ans.begin() + 1, ans.end());
			res.push_back(ans);
        }
	}
	return res;
}

void search_DFS(vector<vector<string>>& accounts, unordered_map<string, vector<int>>& graph, int index,
			   unordered_set<int>& visited, unordered_set<string>& merge)
{
	for(int i = 1; i < accounts[index].size(); i++)
	{
		for(int v : graph[accounts[index][i]])
		{
			if(!visited.count(v))
			{
				visited.insert(v);
				for(int j = 1; j < accounts[v].size(); j++)
                    merge.insert(accounts[v][j]);
				search_DFS(accounts, graph, v, visited, merge);
			}
		}
	}
}

// union find
int find(vector<int>& parent, int x)
{
	if(x == parent[x]) return x;
	parent[x] = find(parent, parent[x]);
    return parent[x];
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	// initialization parent array
	vector<int> parent(accounts.size());
	for(int i = 0; i < accounts.size(); i++)
		parent[i] = i;
	
	unordered_map<string, int> email_id;    // email = > group_id
	for(int i = 0; i < accounts.size(); i++)
	{
		for(int j = 1; j < accounts[i].size(); j++)
		{
			if(email_id.find(accounts[i][j]) != email_id.end())
			{
				// if current email has existed, union it's group
				int old_parent = find(parent, email_id[accounts[i][j]]);
				int current_parent = find(parent, i);
				parent[current_parent] = old_parent;
			}
			else
				email_id[accounts[i][j]] = i;
		}
	}
	
	unordered_map<int, vector<string>> merge;
	for(auto p : email_id)
	{
		int root = find(parent, p.second);  // find the email's root(top most)
		merge[root].push_back(p.first);
	}
	
	vector<vector<string>> ans;
	for(auto it : merge)
	{
		vector<string> temp = {accounts[it.first][0]};
		sort(it.second.begin(), it.second.end());
		for(auto s : it.second) temp.push_back(s);
		ans.push_back(temp);
	}
	
	return ans;
}

// BFS
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	unordered_map<string, vector<int>> graph;   // email => group_id
	for(int i = 0; i < accounts.size(); i++)
	{
		for(int j = 1; j < accounts[i].size(); j++)
		{
			graph[accounts[i][j]].push_back(i);
		}
	}
	
	unordered_set<int> visited;  // 有哪些group已经被访问过了
	vector<vector<string>> ans;
	for(int i = 0; i < accounts.size(); i++)
	{
		if(!visited.count(i))
		{
			visited.insert(i);
			unordered_set<string> merge(accounts[i].begin() + 1, accounts[i].end());
			search_BFS(accounts, graph, visited, i, merge);

			vector<string> temp = {accounts[i][0]};
			temp.insert(temp.end(), merge.begin(), merge.end());
			sort(temp.begin() + 1, temp.end());
			ans.push_back(temp);
		}
	}
	
	return ans;
}

void search_BFS(vector<vector<string>>& accounts,
				unordered_map<string, vector<int>>& graph,
				unordered_set<int>& visited, int curr, unordered_set<string>& merge)
{
	queue<int> q;
	q.push(curr);
	while(!q.empty())
	{
		int size = q.size();
		for(int i = 0; i < size; i++)
		{
			int id = q.front(); q.pop();
			for(int j = 1; j < accounts[id].size(); j++)
			{
				for(int nb : graph[accounts[id][j]])
				{
					if(!visited.count(nb))
					{
						visited.insert(nb);
						q.push(nb);
						
						for(int k = 1; k < accounts[nb].size(); k++)
							merge.insert(accounts[nb][k]);
					}
				}
			}
		}
	}
}






























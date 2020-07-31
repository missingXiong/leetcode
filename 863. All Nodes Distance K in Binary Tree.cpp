vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
{
	if(root == nullptr) return {};

	unordered_map<int, vector<int>> graph;
	buildGraph(root, graph);
	
	unordered_set<int> visited;
	queue<int> q;
	q.push(target->val);
	visited.insert(target->val);
	
	while(!q.empty() && --K >= 0)
	{
		int size = q.size();
		while(size--)
		{
			int curr = q.front(); q.pop();
			for(int nxt : graph[curr])
			{
				if(!visited.count(nxt))
				{
					visited.insert(nxt);
					q.push(nxt);
				}
			}
		}
	}
	
	vector<int> ans;
	while(!q.empty())
	{
		ans.push_back(q.front());
		q.pop();
	}
	
	return ans;
}


void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& graph)
{
	if(root == nullptr) return;
	
	if(root->left != nullptr)
	{
		graph[root->val].push_back(root->left->val);
		graph[root->left->val].push_back(root->val);
	}
	
	if(root->right != nullptr)
	{
		graph[root->val].push_back(root->right->val);
		graph[root->right->val].push_back(root->val);
	}
	
	buildGraph(root->left, graph);
	buildGraph(root->right, graph);	
}
typedef tuple<TreeNode*, int, int> TII;

vector<vector<int>> verticalTraversal(TreeNode* root)
{
	auto cmp = [](vector<int>& lhs, vector<int>& rhs)
				{
					if(lhs[0] != rhs[0])
						return lhs[0] < rhs[0];
					else if(lhs[1] != rhs[1])
						return lhs[1] > rhs[1];
					else 
						return lhs[2] < rhs[2];
				};
	priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);   // vector<x, y, value>
	
	queue<TII> q;
	q.emplace(root, 0, 0);
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			auto v = q.front(); q.pop();
			TreeNode* node = nullptr;
			int x , y;
			std::tie(node, x, y) = v;
			
			pq.push({x, y, node->val});
			
			if(node->left) q.emplace(node->left, x - 1, y - 1);
			if(node->right) q.emplace(node->right, x + 1, y - 1);
		}
	}
	
	vector<vector<int>> ans;
	int curr = 1e9 + 7;
	vector<int> temp;
	while(!pq.empty())
	{
		vector<int> v = pq.top(); pq.pop();
		if(v[0] != curr)
		{
			if(!temp.empty()) ans.push_back(temp);
			temp.clear();
			curr = v[0];
		}
		
		temp.push_back(v[2]);
	}
	
	if(!temp.empty()) ans.push_back(temp);
	return ans;
}

// another crazy method: map<int, map<int, sorted_vector<int>>>  =>  map<x, map<y, sorted_vectot<value>>>










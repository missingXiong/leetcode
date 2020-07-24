
// using one queue: more efficient
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> ans;
	if(root == nullptr) return ans;
	int level = 0;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		int size = q.size();
		vector<int> vec(size);
		for(int i = 0; i < size; i++)
		{
			TreeNode* node = q.front(); q.pop();
			
			int index = level % 2 == 0 ? i : size - i - 1;
			vec[index] = node->val;
			
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		ans.push_back(vec);
		level++;
	}
	return ans;
}

// using two stack
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> ans;
	if(root == nullptr) return ans;
	int level = 0;
	stack<TreeNode*> pop_stack, push_stack;
	pop_stack.push(root);
	while(!pop_stack.empty())
	{
		int size = pop_stack.size();
		vector<int> vec;
		while(size--)
		{
			TreeNode* node = pop_stack.top(); pop_stack.pop();
			vec.push_back(node->val);
			
			if(level % 2 == 0)
			{
				if(node->left) push_stack.push(node->left);
				if(node->right) push_stack.push(node->right);
			}
			else
			{
				if(node->right) push_stack.push(node->right);
				if(node->left) push_stack.push(node->left);
			}
			
		}
		ans.push_back(vec);
		level++;
		swap(pop_stack, push_stack);
	}
	return ans;
}

// using recursion












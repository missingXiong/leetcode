vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
	stack<TreeNode*> stk1, stk2;
	pushLeft(stk1, root1);
	pushLeft(stk2, root2);
	
	vector<int> ans;
	while(!stk1.empty() || !stk2.empty())
	{
		stack<TreeNode*>& s = stk1.empty() ? stk2 : stk2.empty() ? stk1 : stk1.top()->val <= stk2.top()->val ? stk1 : stk2;
		
		TreeNode* curr = s.top();
		ans.push_back(curr->val);
		s.pop();
		pushLeft(s, curr->right);
	}
	
	return ans;
}

void pushLeft(stack<TreeNode*>& stk, TreeNode* node)
{
	while(node != nullptr)
	{
		stk.push(node);
		node = node->left;
	}
}
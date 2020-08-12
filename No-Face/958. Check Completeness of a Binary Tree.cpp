
bool isCompleteTree(TreeNode* root)
{
	queue<TreeNode*> q;
	q.push(root);
	
	bool seenEmpty = false;
	while(!q.empty())
	{
		TreeNode* node = q.front(); q.pop();
		
		if(node == nullptr)
		{
			seenEmpty = true;
			continue;
		}
		else if(seenEmpty)
			return false;
		
		q.push(node->left);
		q.push(node->right);
	}
	
	return true;
}
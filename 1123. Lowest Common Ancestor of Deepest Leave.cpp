TreeNode* lcaDeepestLeaves(TreeNode* root)
{
	if(root == nullptr) return nullptr;
	
	return helper(root).first;
}

pair<TreeNode*, int> helper(TreeNode* root)
{
	if(root == nullptr) return {nullptr, 0};
	
	pair<TreeNode*, int> left = helper(root->left);
	pair<TreeNode*, int> right = helper(root->right);
	
	if(left.second == right.second)
		return {root, left.second + 1};
	else
		return {left.second < right.second ? right.first : left.first, max(right.second, left.second) + 1};
}
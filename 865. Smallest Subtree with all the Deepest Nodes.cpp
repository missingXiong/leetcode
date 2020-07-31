TreeNode* subtreeWithAllDeepest(TreeNode* root)
{
	pair<TreeNode*, int> ans = helper(root, 0);
	return ans.first;
}


pair<TreeNode*, int> helper(TreeNode* root, int depth)
{
	if(root == nullptr) return {nullptr, 0};
	
	auto l = helper(root->left, depth + 1);
	auto r = helper(root->right, depth + 1);
	
	if(l.second == r.second)
		return {root, l.second + 1};
	else
		return {l.second < r.second ? r.first : l.first, max(l.second, r.second) + 1};
}
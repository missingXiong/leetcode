
vector<int> largestValues(TreeNode* root)
{
	vector<int> ans;
	helper(root, 0, ans);
	return ans;
}

void helper(TreeNode* root, int level, vector<int>& ans)
{
	if (root == nullptr) return;
	if (level == ans.size())
		ans.push_back(root->val);
	ans[level] = max(ans[level], root->val);
	helper(root->left, level + 1, ans);
	helper(root->right, level + 1, ans);
}
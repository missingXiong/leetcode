

int diameterOfBinaryTree(TreeNode* root)
{
	if(root == nullptr);
	int ans = 0;
	maxDepth(root, ans);
	return ans;
}

int maxDepth(TreeNode* root, int& maxVal)
{
	if(root == nullptr) return 0;
	int left = maxDepth(root->left, maxVal);
	int right = maxDepth(root->right, maxVal);
	maxVal = max(maxVal, left + right);
	return max(left, right);
}
int ans = 0;
void helper(TreeNode* root, int minVal, int maxVal)
{
	if(root == nullptr) return;
	
	ans = max(ans, max(abs(root->val - minVal), abs(root->val - maxVal)));
	helper(root->left, min(minVal, root->val), max(maxVal, root->val));
	helper(root->right, min(minVal, root->val), max(maxVal, root->val));
}

int maxAncestorDiff(TreeNode* root)
{
	if(root == nullptr) return 0;
	helper(root, root->val, root->val);   // preorder
	return ans;
}


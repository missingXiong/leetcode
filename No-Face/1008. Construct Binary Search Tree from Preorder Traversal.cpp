TreeNode* bstFromPreorder(vector<int>& preorder)
{
	return helper(preorder, INT_MIN, INT_MAX);
}

int i = 0;
TreeNode* helper(vector<int>& preorder, int low_bound, int up_bound)
{
	if(i >= preorder.size() || preorder[i] > up_bound || preorder[i] < low_bound) return nullptr;
	
	TreeNode* root = new TreeNode(preorder[i++]);
	root->left = helper(preorder, low_bound, root->val);
	root->right = helper(preorder, root->val, up_bound);
	
	return root;
}
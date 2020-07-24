

int pathSum(TreeNode* root, int sum)
{
	if(root == nullptr) return 0;
	return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int helper(TreeNode* root, int target)
{
	if(root == nullptr) return 0;
	
	int cnt = 0;
	if(root->val == target) cnt++;
	cnt += helper(root->left, target - root->val);
	cnt += helper(root->right, target - root->val);
	return cnt;
}
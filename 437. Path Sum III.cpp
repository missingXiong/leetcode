
// recursion
int pathSum(TreeNode* root, int sum)
{
	if (root == nullptr) return 0;
	int count = findTarget(root, sum);
	count += pathSum(root->left, sum);
	count += pathSum(root->right, sum);
	return count;
} 

int findTarget(TreeNode* root, int target)
{
	if (root == nullptr) return 0;
	
	int count = 0;
	if (root->val == target) count++;
	count += findTarget(root->left, target - root->val);
	count += findTarget(root->right, target - root->val);
	return count;
}

// prefix sum
int pathSum(TreeNode* root, int sum)
{
	unordered_map<int, int> prefix_sum = {{0, 1}};   // <prefix sum, count>
	return findTarget(root, 0, sum, prefix_sum);
}

int findTarget(TreeNode* root, int curr_sum, int target, unordered_map<int, int>& prefix_sum)
{
	if (root == nullptr) return 0;
	
	curr_sum += root->val;
	int count = 0;
	if (prefix_sum.count(curr_sum - target))
		count += prefix_sum[curr_sum - target];
	
	// backtracking
	prefix_sum[curr_sum]++;
	count += findTarget(root->left, curr_sum, target, prefix_sum);
	count += findTarget(root->right, curr_sum, target, prefix_sum);
	prefix_sum[curr_sum]--;
	return count;
}
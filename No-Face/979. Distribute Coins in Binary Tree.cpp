int distributeCoins(TreeNode* root)
{
	int moves = 0;
	helper(root, moves);
	return moves;
}


int helper(TreeNode* root, int& moves)
{
	if(root == nullptr) return 0;
	
	int left = helper(root->left, moves);
	int right = helper(root->right, moves);
	
	int remain = left + right + root->val - 1;
	moves += abs(remain);
	
	return remain;
}
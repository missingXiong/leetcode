

// Because we have 3000 nodes
// If each level has at most two nodes, the tree will have 1500 level
// the index will be 2^1500, so we need use unsigned long
int widthOfBinaryTree(TreeNode* root)
{
	vector<vector<unsigned long>> record; // level -> {minIndex, maxIndex}
	helper(root, 1, 0, record);

	return ans;
}

int ans = 0;
void helper(TreeNode* root, unsigned long index, int level, vector<vector<unsigned long>>& record)
{
	if (root == nullptr) return;
	
	if (record.size() == level)
		record.push_back({index, index});
	
	record[level][1] = index;
	ans = max(ans, (int)(record[level][1] - record[level][0] + 1));
	
	helper(root->left, 2 * index, level + 1, record);
	helper(root->right, 2 * index + 1, level + 1, record);
}

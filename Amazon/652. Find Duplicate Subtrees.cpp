

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
	vector<TreeNode*> ans;
	unordered_map<string, int> count;
	postorder(root, count, ans);
	return ans;
}

string postorder(TreeNode* root, unordered_map<string, int>& count, vector<TreeNode*>& ans)
{
	if(root == nullptr) return "#";
	string left = postorder(root->left, count, ans);
	string right = postorder(root->right, count, ans);
	
	string s = left + "," + right + "," + to_string(root->val);
	if(++count[s] == 2)
		ans.push_back(root);
	return s;
}

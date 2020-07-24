
typedef tuple<int, int, TreeNode*> tp;  // <x, y, val>
struct cmp
{
	bool operator() (const tp& lt, const tp& rt)
	{
		if(get<0>(lt) != get<0>(rt))
			return get<0>(lt) > get<0>(rt);
		else if(get<1>(lt) != get<1>(rt))
			return get<1>(lt) < get<1>(rt);
		else
			return get<2>(lt) > get<2>(rt);
	}
};

vector<vector<int>> verticalTraversal(TreeNode* root)
{
	if(root == nullptr) return {};
	
	vector<tp> vc;
	helper(root, 0, 0, vc);
	
	stable_sort(vc.begin(), vec.end(), cmp);
	
	vector<vector<int>> ans;
	int curr_x = INT_MIN;
	for(int i = 0; i < vc.size(); i++)
	{
		auto [x, y, node] = vc[i];
		if(x == curr_x)
			ans.back().push_back(node->val);
		else
		{
			vector<int> temp;
			temp.push_back(node->val);
			ans.push_back(temp);
		}
	}
	return ans;
}

void helper(TreeNode* root, int x, int y, vector<tp>& vc)
{
	if(root == nullptr) return;
	vc.emplace_back(x, y, root);
	helper(root->left, x - 1, y - 1, vc);
	helper(root->right, x + 1, y - 1, vc);
}
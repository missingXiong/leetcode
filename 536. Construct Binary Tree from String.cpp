TreeNode* str2tree(string s)
{
	return helper(s);
}

int i = 0;
TreeNode* helper(string& s)
{
	TreeNode* root = nullptr;
	int num = 0;
	bool negative = false;
	while (i < s.length())
	{
		if (isdigit(s[i]))
		{
			num = num * 10 + (s[i] - '0');
            int val = negative ? -1 * num : num;
			if (root == nullptr) root = new TreeNode(val);
			else root->val = val;
		}
		else if (s[i] == '-')
			negative = true;
		else if (s[i] == '(')
		{
			if (root->left == nullptr)
			{
                ++i;
				root->left = helper(s);
			}
			else
			{
                ++i;
				root->right = helper(s);
			}
		}
		else if (s[i] == ')')
		{
			return root;
		}
		++i;
	}
	
	return root;
}


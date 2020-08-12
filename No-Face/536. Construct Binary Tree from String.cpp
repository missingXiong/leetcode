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

TreeNode* str2tree(string s)
{
	int len = s.length();
	if (len == 0) return nullptr;
	stack<TreeNode*> stk;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ')')
		{
			 stk.pop();
		}
		else if (isdigit(s[i]) || s[i] == '-')
		{
			int num = 0;
			bool negative = false;
			if (s[i] == '-')
			{
				negative = true;
				i++;
			}
			
			while (isdigit(s[i]))
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			i--;
			int val = negative ? -1 * num : num;
			TreeNode* node = new TreeNode(val);
			
			if (!stk.empty())
			{
				if ((stk.top())->left == nullptr)
					(stk.top())->left = node;
				else
					(stk.top())->right = node;
			}
			stk.push(node);
		}
	}
	
	return stk.top();
}































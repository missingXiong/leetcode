

// implict space: O(n)
void recoverTree(TreeNode* root)
{
	inorder(root);
	swap(first->val, second->val);
}

TreeNode* preNode = nullptr, * first = nullptr, * second = nullptr;

void inorder(TreeNode* root)
{
	if(root == nullptr) return;
	
	inorder(root->left);
	if(preNode && preNode->val > root->val)
	{
		if(first == nullptr) first = preNode;
		second = root;
	}
	preNode = root;
	inorder(root->right);
}

// morris inorder traversal
void recoverTree(TreeNode* root)
{
	Morris_Inorder(root);
	swap(first->val, second->val);
}

TreeNode* first = nullptr, * second = nullptr, * preNode = nullptr;
void check(TreeNode* node)
{
	if(preNode && preNode->val > node->val)
	{
		if(first == nullptr) first = preNode;
		second = node;
	}
	preNode = node;
}

void Morris_Inorder(TreeNode* root)
{
	TreeNode* curr = root;
	while(curr != nullptr)
	{
		if(curr->left == nullptr)   // curr已经到达left-most
		{
			check(curr);
			curr = curr->right;
		}
		else
		{
			TreeNode* pre = curr->left;
			
			// find the right-most node of pre(find predecessor of curr)
			while(pre->right != nullptr && pre->right != curr)
				pre = pre->right;
			

			if(pre->right != nullptr)
			{
				/*如果已经存在从pre指向curr的link，则销毁link
				且说明此时curr已经访问了leftchild，之后先访问curr节点，在访问rightchild*/
				pre->right = nullptr;
				check(curr);
				curr = curr->right;
			}
			else
			{
				/*不存在pre到curr的link，则建立link，且访问curr的leftchild*/
				pre->right = curr;
				curr = curr->left;
			}
		}
	}
}

// preorder 和 inorder建立连接的方式一模一样，代码只有细微差别
void Morris_Preorder(TreeNode* root)
{
	TreeNode* curr = root;
	while(curr != nullptr)
	{
		if(curr->left == nullptr)
		{
			visit(curr);
			curr = curr->right;
		}
		else
		{
			TreeNode* pre = curr->left;
			while(pre->right && pre->right != curr)
				pre = pre->right;
			if(pre->right == curr)
			{
				pre->right = nullptr;
				curr = curr->right;
			}
			else
			{
				visit(curr);
				pre->right = curr;
				curr = curr->left;
			}
		}
	}
}
































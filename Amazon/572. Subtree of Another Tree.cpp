


100. Same Tree
101. Symmetric Tree

bool match(TreeNode* s, TreeNode* t)
{
	if(s == nullptr && t == nullptr) return true;
	if(s == nullptr || t == nullptr) return false;
	
	return s->val == t->val && match(s->left, t->left) && match(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
	if(!s) return false;
	return match(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}


/*
(1) get the height of t
(2) save nodes in s which height are equal to h(t)
(3) compare nodes with t
*/
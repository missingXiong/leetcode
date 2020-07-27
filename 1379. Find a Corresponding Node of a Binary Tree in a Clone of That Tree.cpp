TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
{
	if(original == nullptr) return nullptr;
	if(original == target) return cloned;
	
	TreeNode* l = getTargetCopy(original->left, cloned->left, target);
	if(l != nullptr) return l;
	
	TreeNode* r = getTargetCopy(original->right, cloned->right, target);
	if(r != nullptr) return r;
	
	// not found
	return nullptr;
}
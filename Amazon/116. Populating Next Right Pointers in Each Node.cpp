

Node* connect(Node* root)
{
	if(root == nullptr) return nullptr;
	
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* curr = q.front(); q.pop();
		if(curr->left && curr->right)
		{
			curr->left->next = curr->right;
			if(curr->next)
				curr->right->next = curr->next->left;
			q.push(curr->left);
			q.push(curr->right);
		}
	}
	return root;
}

Node* connect(Node* root)
{
	if(root == nullptr) return nullptr;
	
	Node* pre = root, * curr;
	while(pre != nullptr)
	{
		curr = pre;
		while(curr != nullptr)
		{
			if(curr->left) curr->left->next = curr->right;
			if(curr->right && curr->next) curr->right->next = curr->next->left;
			curr = curr->next;
		}
		pre = pre->left;
	}
	return root;
}
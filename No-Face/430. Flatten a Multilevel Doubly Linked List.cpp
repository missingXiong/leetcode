
Node* flatten(Node* head)
{
	if (head == nullptr) return nullptr;
	
	Node* curr = head;
	while(curr != nullptr)
	{
		if (curr->child == nullptr)
		{
			curr = curr->next;
			continue;
		}
		
		Node* nxt = curr->next;
		curr->next = curr->child;
		curr->child = nullptr;
		curr->next->prev = curr;
		
		Node* tail = curr->next;
		while (tail->next != nullptr)
			tail = tail->next;
		
		if (nxt != nullptr) 
		{
			tail->next = nxt;
			nxt->prev = tail;
		}
		
		curr = curr->next;
	}
	
	return head;
}

Node* pre = nullptr;
Node* flatten(Node* head)
{
	if (head == nullptr) return nullptr;
	
	flatten(head->next);
	flatten(head->child);
	
	head->next = pre;
	if (pre != nullptr) pre->prev = head;
	head->child = nullptr;
	pre = head;
	return head;
}

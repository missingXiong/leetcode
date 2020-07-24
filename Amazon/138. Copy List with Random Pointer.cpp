
// time complexity : O(n) space complexity : O(n)
Node* copyRandomList(Node* head)
{
	Node* newHead = copyHead(head);
	
	Node* temp = newHead;
	while(head != nullptr)
	{
		if(head->random == nullptr) temp->random = nullptr;
		else
		{
			int index = node_index[head->random];
			temp->random = nodes[index];
		}
		head = head->next;
		temp = temp->next;
	}
	return newHead;
}

vector<Node*> nodes;
unordered_map<Node*, int> node_index;
Node* copyHead(Node* head)
{
	Node dummy(0);
	Node* curr = &dummy;
	int index = 0;
	while(head != nullptr)
	{
		Node* node = new Node(head->val);
		node_index[head] = index++; 
		nodes.push_back(node);
		curr->next = node;
		curr = curr->next;
		head = head->next;
	}
	return dummy.next;
}

// recursion  :   6666666666666
unordered_map<Node*, Node*> map;
Node* copyRandomList(Node* head)
{
	if(head == nullptr) return nullptr;
	if(map[head]) return map[head];
	
	map[head] = new Node(head->val);
	map[head]->random = copyRandomList(head->random);
	map[head]->next = copyRandomList(head->next);
	return map[head];
}
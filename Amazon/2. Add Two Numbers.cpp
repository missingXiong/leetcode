

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode dummy(-1);
	ListNode* head = &dummy;
	int sum = 0; 
	while(l1 || l2 || sum)
	{
		if(l1) sum += l1->val;
		if(l2) sum += l2->val;
		ListNode* node = new ListNode(sum % 10);
		sum /= 10;
		head->next = node;
		head = head->next;
		if(l1) l1 = l1->next;
		if(l2) l2 = l2->next;
	}
	
	return dummy.next;
}

445. Add Two Numbers II

// reverse
// stack
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	stack<int> s1;
	stack<int> s2;
	
	ListNode dummy(1);
	ListNode* head = &dummy;
	
	while(l1 != nullptr) { s1.push(l1->val); l1 = l1->next; }
	while(l2 != nullptr) { s2.push(l2->val); l2 = l2->next; }
	
	int carry = 0;
	while(!s1.empty() || !s2.empty() || carry)
	{
		if(!s1.empty()) {carry += s1.top(); s1.pop();}
		if(!s2.empty()) {carry += s2.top(); s2.pop();}
		ListNode* node = new ListNode(carry % 10);
		node->next = head->next;
		head->next = node;
		carry /= 10;
	}
	return dummy.next;
}


// recursion
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(l1 == nullptr && l2 == nullptr) return nullptr;
	
	ListNode dummy(1);
	ListNode* head = &dummy;
	
	int len1 = 0, len2 = 0;
	for(ListNode* p = l1; p != nullptr; p = p->next) len1++;
	for(ListNode* p = l2; p != nullptr; p = p->next) len2++;
	
	if(len1 < len2) swap(l1, l2);
	head->next = helper(l1, l2, abs(len1 - len2));
	if(node->val > 9)
	{
		head->next->val = head->next->val % 10;
		return head;
	}
	return head->next;
}

ListNode* helper(ListNode* l1, ListNode* l2, int diff)
{
	if(l1 == nullptr && l2 == nullptr) return nullptr;
	ListNode* left = diff == 0 ? new ListNode(l1->val + l2->val)
		: new ListNode(l1->val);
	ListNode* right = diff == 0 ? helper(l1->next, l2->next, 0)
		: helper(l1->next, l2, diff - 1);
	
	if(right != nullptr)
	{
		left->val += right->val / 10;
		right->val = right->val % 10;
	}
	left->next = right;
	return left;
}
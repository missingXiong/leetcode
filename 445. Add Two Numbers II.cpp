ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr || l2 == nullptr)
		return l1 ? l1 : l2;
	
	int len1 = 0; int len2 = 0;
	for (ListNode* node = l1; node != nullptr; node = node->next) len1++;
	for (ListNode* node = l2; node != nullptr; node = node->next) len2++;
	
	if (len1 < len2) swap(l1, l2);
	int diff = abs(len1 - len2);
	TreeNode* node = traverse(l1, l2, diff);
	if (node->val / 10)
	{
		ListNode* temp = new ListNode(node->val / 10);
		node->val = node->val % 10;
		node = temp;
	}
	return node;
}

TreeNode* traverse(ListNode* l1, ListNode* l2, int diff)
{
	if (l1 == nullptr && l2 == nullptr) return nullptr;
	
	int val = diff ? l1->val : l1->val + l2->val;
	TreeNode* nxt = diff ? l2 : l2->next;
	ListNode* left = new ListNode(val);
	ListNode* right = traverse(l1->next, nxt, diff ? diff - 1 : 0);
	
	if (right != nullptr && right / 10)
	{
		right->val = right->val % 10;
		left->val += 1;
	}
	return left;
}

// stack
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    stack<ListNode*> s1, s2, s3;
    while(l1 != nullptr)
    {
        s1.push(l1);
        l1 = l1->next;
    }
    while(l2 != nullptr)
    {
        s2.push(l2);
        l2 = l2->next;
    }
    int sum = 0;
    while(!s1.empty() || !s2.empty() || sum)
    {
        sum += (s1.empty() ? 0 : s1.top()->val) + (s2.empty() ? 0 : s2.top()->val);
        if(!s1.empty()) s1.pop();
        if(!s2.empty()) s2.pop();
        ListNode* node = new ListNode(sum % 10);
        s3.push(node);
        sum /= 10;
    }
    
    ListNode dummy(0);
    ListNode* head = &dummy;
    while(!s3.empty())
    {
        head->next = s3.top(); s3.pop();
        head = head->next;
    }
    return dummy.next;
}
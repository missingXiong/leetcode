

ListNode* reverseKGroup(ListNode* head, int k)
{
	if(head == nullptr || k == 1) return head;
	
	ListNode dummy(-1);
	ListNode* pre = &dummy;
	pre->next = head;

	ListNode* curr = head, * nxt = nullptr;
	int len = 0;
	for(; curr != nullptr; curr = curr->next) len++;
	
	for(int i = 0; i < len / k; i++)
	{
		for(int j = 1; j < k; j++)
		{
			ListNode* temp = pre->next;
			pre->next = head->next;
			head->next = head->next->next;
			pre->next->next = temp;
		}
		pre = head;
		head = head->next;
	}
	return dummy.next;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
	if(head == nullptr || k == 1) return head;
	
	ListNode dummy(-1);
	ListNode* pre = &dummy;
	pre->next = head;

	ListNode* temp = head;
	int len = 0;
	for(; temp != nullptr; temp = temp->next) len++;
	
	ListNode* tail = nullptr, * curr = nullptr, * nxt = nullptr;
	while(len >= k)
	{
		tail = pre->next;
		curr = tail->next;
		for(int i = 1; i < k; i++)
		{
			nxt = curr->next;
			curr->next = pre->next;
			pre->next = curr;
			tail->next = nxt;
			curr = nxt;
		}
		pre = tail;
		len -= k;
	}
	return dummy.next;
}
























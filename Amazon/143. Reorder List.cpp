
// recursion
void reorderList(ListNode* head)
{
	if(head == nullptr) return;
	p = head;
	helper(head);
}

ListNode* p = nullptr;
bool isFinish = false;
void helper(ListNode* head)
{
	if(head == nullptr) return;
	
	helper(head->next);
	
	if(!isFinish)
	{
		if(p == head || (p && p->next == head))
		{
			isFinish = true;
			head->next = nullptr;
			return;
		}
		head->next = p->next;
		p->next = head;
		p = p->next->next;
	}
}

// iterator
// 1. find middle, and seperate to two linked lists
// 2. reverse the second list
// 3. merge two linked list into one
void reorderList(ListNode* head)
{
	if(head == nullptr || head->next == nullptr) return;
	
	ListNode* slow = head, *fast = head, * pre = nullptr;
	while(fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = nullptr;
	
	ListNode* middle = reverseList(slow);
	
	// merge two list
	merge(head, middle);
}

ListNode* reverseList(ListNode* head)
{
	if(head== nullptr || head->next == nullptr) return head;
	
	ListNode* curr = head, * pre = nullptr, * nxt = nullptr;
	while(curr)
	{
		nxt = curr->next;
		curr->next = pre;
		pre = curr;
		curr = nxt;
	}
	return pre;
}

void merge(ListNode* l1, ListNode* l2)
{
	while(l1->next)
	{
		ListNode* n1 = l1->next, * n2 = l2->next;
		l2->next = n1;
		l1->next = l2;
		l1 = n1;
		l2 = n2;
	}
	l1->next = l2;
}



















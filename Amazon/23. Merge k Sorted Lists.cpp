


ListNode* mergeKLists(vector<ListNode*>& lists)
{
	auto cmp = [](ListNode* l, ListNode* r){return l->val > r->val;};
	priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
	for(ListNode* p : lists)
		if(p) minHeap.push(p);
	
	ListNode dummy(0);
	ListNode* curr = &dummy;
	while(!minHeap.empty())
	{
		ListNode* node = minHeap.top(); minHeap.pop();
		curr->next = node;
		curr = curr->next;
		if(node->next) minHeap.push(node->next);
	}
	return dummy.next;
}
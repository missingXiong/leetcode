
vector<int> nextLargerNodes(ListNode* head)
{
	stack<int> stk;
	vector<int> ans;
	helper(head, stk, ans);
	std::reverse(ans.begin(), ans.end());
	return ans;
}

void helper(ListNode* head, stack<int>& stk, vector<int>& ans)
{
	if(head == nullptr) return;
	
	helper(head->next, stk, ans);
	while(!stk.empty() && head->val >= stk.top())
		stk.pop();
	
	int num = stk.empty() ? 0 : stk.top();
	ans.push_back(num);
	stk.push(head->val);
}


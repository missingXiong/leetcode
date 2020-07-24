

vector<int> dailyTemperatures(vector<int>& T)
{
	int size = T.size(); 
	if(size == 0) return {};
	vector<int> ans(size);
	stack<pair<int, int>> stk;   // <temperature, index>
	for(int i = size - 1; i >= 0; i--)
	{
		while(!stk.empty() && T[i] >= stk.top().first) stk.pop();
		ans[i] = stk.empty() ? 0 : stk.top().second - i;
		stk.emplace(T[i], i);
	}
	return ans;
}
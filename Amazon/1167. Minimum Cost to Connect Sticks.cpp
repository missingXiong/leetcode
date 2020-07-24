

int connectSticks(vector<int>& sticks)
{
	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
	while(pq.size() > 1)
	{
		int p = pq.top(); pq.pop();
		int q = pq.top(); pq.pop();
		pq.push(p + q);
		ans += p + q;
	}
	return ans;
}
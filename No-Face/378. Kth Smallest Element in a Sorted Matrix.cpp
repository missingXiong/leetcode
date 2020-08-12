int kthSmallest(vector<vector<int>>& matrix, int k)
{
	int m = matrix.size();
	int n = matrix[0].size();
	
	auto cmp = [&matrix](pair<int, int> a, pair<int, int> b)
				{ return matrix[a.first][a.second] > matrix[b.first][b.second]; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
	
	// push the first element in each rows
	for(int i = 0; i < m; i++)
		pq.emplace(i, 0);
	
	int res = 0;
	while(!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		if(k-- == 1) res = matrix[p.first][p.second];
		if(p.second + 1 < n) pq.emplace(p.first, p.second + 1);
	}
	return res;
}
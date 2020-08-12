
vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
{
	int m = workers.size();
	int n = bikes.size();
	vector<int> assign(m);
	vector<bool> workersPool(m, false);
	vector<bool> bikesPool(n, false);

	auto cmp = [&workers, &bikes](pair<int, int> a, pair<int, int> b) // pair<worker_index, bike_index>
			{
				int d1 = abs(workers[a.first][0] - bikes[a.second][0]) + abs(workers[a.first][1] - bikes[a.second][1]);
				int d2 = abs(workers[b.first][0] - bikes[b.second][0]) + abs(workers[b.first][1] - bikes[b.second][1]);
				if(d1 != d2)
					return d1 < d2;
				else if(a.first != b.first)
					return a.first < b.first;
				else
					return a.second < b.second;
			};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			pq.emplace(i, j);
		
	while(!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		if(!workersPool[p.first] && !bikesPool[p.second])
		{
			assign[p.first] = p.second;
			workersPool[p.first] = true;
			bikesPool[p.second] = true;
		}
	}
	return assign;
}
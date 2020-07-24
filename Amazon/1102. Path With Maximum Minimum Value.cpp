
typedef tuple<int, int, int> tp;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
int maximumMinimumPath(vector<vector<int>>& A)
{
	int m = A.size();
	int n = A[0].size();
	int minVal = INT_MAX;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	priority_queue<tp> pq;
	pq.emplace(A[0][0], 0, 0);
	visited[0][0] = true;
	while(!pq.empty())
	{
		auto [val, x, y] = pq.top(); pq.pop();
		minVal = min(minVal, val);
		if(x == m - 1 && y == n - 1) break;
		for(int i = 0; i < 4; i++)
		{
			int ix = x + dx[i];
			int iy = y + dy[i];
			if(ix < 0 || ix >= m || iy < 0 || iy >= n || visited[ix][iy])
				continue;
			visited[ix][iy] = true;
			pq.emplace(A[ix][iy], ix, iy);
		}
	}
	return minVal;
}
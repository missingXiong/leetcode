vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
void dfs(int x, int y, vector<vector<bool>>& visited, queue<pair<int, int>>& q, vector<vector<int>>& A, int m, int n)
{
	if(x < 0 || x >= m || y < 0 || y >= n || A[x][y] == 0 || visited[x][y])
		return;
	
	visited[x][y] = true;
	q.emplace(x, y);
	for(int i = 0; i < 4; i++)
	{
		dfs(x + dirs[i][0], y + dirs[i][1], visited, q, A, m, n);
	}
}

int shortestBridge(vector<vector<int>>& A)
{
	int m = A.size(), n = A[0].size();
	
	// find first island
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	queue<pair<int, int>> q;
	bool findFirst = false;
	for(int i = 0; i < m; i++)
	{
		if(findFirst) break;
		for(int j = 0; j < n; j++)
		{
			if(A[i][j] == 1 && !findFirst)
			{
				findFirst = true;
				dfs(i, j, visited, q, A, m, n);
				break;
			}
		}
	}
	
	// expand the island until find a node that has not been visited and value == 1
	int step = 0;
	while(!q.empty())
	{
		int size = q.size();
		step++;
		for(int i = 0; i < size; i++)
		{
			auto pos = q.front(); q.pop();
			int x = pos.first;
			int y = pos.second;
			
			for(int j = 0; j < 4; j++)
			{
				int ix = pos.first + dirs[j][0];
				int iy = pos.second + dirs[j][1];
				
				if (ix >= 0 && ix < m && iy >= 0 && iy < n && !visited[ix][iy])
				{
					if(A[ix][iy] == 1) return step;
					visited[ix][iy] = true;
					q.emplace(ix, iy);
				}
			}
		}
	}
	
	return -1;
}



























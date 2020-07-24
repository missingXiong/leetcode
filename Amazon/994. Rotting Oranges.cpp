
// DFS会比较复杂
int orangesRotting(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	int ans = 0;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == 2)
			{
				int t = dfs(-1, m, n, i, j, grid);
				ans = max(ans, t);
			}	
		}
	}
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(grid[i][j] == 1) return -1;
	return ans;
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
int dfs(int time, int m, int n, int x, int y, vector<vector<int>>& grid)
{
	if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 3 || grid[x][y] == 0)
		return time;
	
	grid[x][y] = 3;
	int maxTime = 0;
	for(int i = 0; i < 4; i++)
	{
		int t = dfs(time + 1, m, n, x + dx[i], y + dy[i], grid);
		maxTime = max(t, maxTime);
	}
	return maxTime;
}

// BFS
/* special case: 
2
1
1
1
2
1
1
time = 2 not 3
*/
/* wrong!!!!!!!!!!!!!!!!!!!!!
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
int orangesRotting(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	
	int ans = 0;
	queue<pair<int, int>> q;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == 2)
			{
				int time = -1;
				grid[i][j] = -1;
				q.push({i, j});
				while(!q.empty())
				{
					time++;
					int size = q.size();
					while(size--)
					{
						auto pos = q.front(); q.pop();
						int x = pos.first, y = pos.second;
						for(int k = 0; k < 4; k++)
						{
							int ix = x + dx[k], iy = y + dy[k];
							if(ix >= 0 && ix < m && iy >= 0 && iy < n && grid[ix][iy] == 1)
							{
								grid[ix][iy] = -1;
								q.push({ix, iy});
							}
						}
					}
				}
				ans = max(ans, time);
			}
		}
	}
	return ans;
}
*/

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
int orangesRotting(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	
	int count = 0, visited = 0;
	queue<pair<int, int>> q;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] != 0) count++;
			if(grid[i][j] == 2) q.push({i, j});
		}
	}
	
	int time = 0;
	while(!q.empty())
	{
		time++;
		int size = q.size();
		visited += size;
		while(size--)
		{
			auto pos = q.front(); q.pop();
			int x = pos.first, y = pos.second;
			for(int k = 0; k < 4; k++)
			{
				int ix = x + dx[k], iy = y + dy[k];
				if(ix >= 0 && ix < m && iy >= 0 && iy < n && grid[ix][iy] == 1)
				{
					grid[ix][iy] = 2;
					q.push({ix, iy});
				}
			}
		}
		if(!q.empty()) time++;
	}
	return visited == count ? time : -1;
}











































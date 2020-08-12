int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	
	int ans = 0;
	unordered_set<int> visited;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == 1)
				ans = max(ans, dfs(grid, visited, i, j, m, n));
		}
	}
	
	return ans;
}

int dfs(vector<vector<int>>& grid, unordered_set<int>& visited, int x, int y, int m, int n)
{
	int tid = x * n + y;
	if(x < 0 || x >= m || y < 0 || y >= n || visited.count(tid) || grid[x][y] == 0)
		return 0;
	
	visited.insert(tid);
	return 1 + dfs(grid, visited, x - 1, y, m, n) + dfs(grid, visited, x + 1, y, m, n) +
		dfs(grid, visited, x, y - 1, m, n) + dfs(grid,visited, x, y + 1, m, n);
}
	
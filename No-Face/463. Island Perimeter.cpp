
vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int islandPerimeter(vector<vector<int>>& grid)
{
	int m = grid.size();
	if (m == 0) return 0;
	int n = grid[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j])
				return dfs(grid, i, j, m, n);
		}
	}
	return 0;
}

bool isValid(vector<vector<int>>& grid, int x, int y, int m, int n)
{
	return x >= 0 && x < m && y >= 0 && y < n;
}

int dfs(vector<vector<int>>& grid, int x, int y, int m, int n)
{
	if (!isValid(grid, x, y, m, n) || grid[x][y] != 1) return 0;
	
	grid[x][y] = 2;
	int ans = 4;
	for (int i = 0; i < 4; i++)
	{
		if (isValid(grid, x + dir[i][0], y + dir[i][1], m, n) && grid[x + dir[i][0]][y + dir[i][1]] != 0)
			ans--;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int nbr = dfs(grid, x + dir[i][0], y + dir[i][1], m, n)；
		ans += nbr;
	}
	return ans;
}
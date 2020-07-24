

int getMaximumGold(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int temp = 0;
			DFS(grid, m, n, i, j, 0, temp);
			ans = max(ans, temp);
		}
	}
	return ans;
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
int DFS(vector<vector<int>>& grid, int m, int n, int x, int y, int curr, int& ans)
{
	if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
		return curr;
	
	int num = grid[x][y];
	grid[x][y] = 0;
	for(int i = 0; i < 4; i++)
	{
		int ix = x + dx[i];
		int iy = y + dy[i];
		int gold = DFS(grid, m, n, ix, iy, curr + num, ans);
		ans = max(ans, gold);
	}
	grid[x][y] = num;
	return curr;
}
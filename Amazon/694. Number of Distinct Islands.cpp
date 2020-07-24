

int numDistinctIslands(vector<vector<int>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	unordered_set<string> set;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == 1)
			{
				string s = "";
				dfs(grid, s, m, n, i, j);
				set.insert(s);
			}
		}
	}
	return set.size();
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1 };
vector<char> mark = {'u', 'l', 'd', 'r'};
void dfs(vector<vector<int>>& grid, string& s, int m, int n, int x, int y)
{
	if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
		return;
	
	grid[x][y] = 0;
	for(int i = 0; i < 4; i++)
	{
		s += mark[i];
		dfs(grid, s, m, n, x + dx[i], y + dy[i]);
	}	
}
vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
	int n = grid.size();
	if(grid[0][0] == 1 || grid[0][0] == 1) return -1;
	
	int steps = 0;
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	
	while(!q.empty())
	{
		steps++;
		int size = q.size();
		while(size--)
		{
			auto pos = q.front(); q.pop();
			for(int i = 0; i < 8; i++)
			{
				int ix = pos.first + dirs[i][0];
				int iy = pos.second + dirs[i][1];
				
				if(ix == n - 1 && iy == n - 1) return steps + 1;
				
				if(ix >= 0 && ix < n && iy >= 0 && iy < n && grid[ix][iy] == 0)
				{
					grid[ix][iy] = 1;
					q.emplace(ix, iy);
				}
			}
		}
	}
	
	return -1;
}
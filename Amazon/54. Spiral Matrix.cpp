
// right down left up
vector<vector<int>> dirctions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;
	if(matrix.size() == 0) return ans;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	int start_x = 0, start_y = 0;
	int dict = 0;
	while(start_x >= 0 && start_x < m && start_y >= 0 && start_y < n && !visited[start_x][start_y])
	{
		int x = start_x, y = start_y;
		while(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
		{
			ans.push_back(matrix[x][y]);
			visited[x][y] = true;
			x += dx[dict % 4];
			y += dy[dict % 4];
		}
			
		x -= dx[dict % 4];
		y -= dy[dict % 4];
		dict++;
		start_x = x + dx[dict % 4];
		start_y = y + dy[dict % 4];
	}
	return ans;
}

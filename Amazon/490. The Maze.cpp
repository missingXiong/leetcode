

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
	if(maze.size() == 0) return false;
	int m = maze.size();
	int n = maze[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	return DFS(maze, start[0], start[1], m, n, destination, visited);
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
bool DFS(vector<vector<int>>& maze, int x, int y, 
		 int m, int n, vector<int>& dest, vector<vector<bool>>& visited)
{
	if(x == dest[0] && y == dest[1]) 
		return true;
	if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
		return false;
	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		int ix = x, iy = y;
		while(ix >= 0 && ix < m && iy >= 0 && iy < n && maze[ix][iy] == 0)
		{
			ix += dx[i];
			iy += dy[i];
		}
		if(DFS(maze, ix - dx[i], iy - dy[i], m, n, dest, visited)) 
			return true;
	}
	
	// 不需要unchoose如果此路是通的，那么explore这个节点时就应该return了
	// 下一次在访问此节点就是浪费时间
	// visited[x][y] = false;  
	return false;
}

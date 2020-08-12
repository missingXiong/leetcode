vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
{
	int m = board.size(), n = board[0].size();
	int x = click[0], y = click[1];
	if (x < 0 || x >= m || y < 0 || y >= n) return board;
	
	if (board[x][y] == 'M')
	{
		board[x][y] = 'X';
		return board;
	}
	
	dfs(board, x, y, m, n);
	return board;
}

vector<vector<int>> dirs = {{1,-1},{ 1,0 },{ 1,1 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 }};
void dfs(vector<vector<char>>& board, int x, int y, int m, int n)
{
	if (!inBoard(x, y, m, n)) return;
	
	if (board[x][y] == 'E')
	{
		// Digits
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			int ix = x + dirs[i][0];
			int iy = y + dirs[i][1];
			if (inBoard(ix, iy, m, n) && board[ix][iy] == 'M')
				count++;
		}
		
		if (count > 0)
			board[x][y] = '0' + count;
		else
		{
			board[x][y] = 'B';
			for (int i = 0; i < 8; i++)
			{
				int ix = x + dirs[i][0];
				int iy = y + dirs[i][1];
				dfs(board, ix, iy, m, n);
			}
		}
	}
}

bool inBoard(int x, int y, int m, int n)
{
	return x >= 0 && x < m && y >= 0 && y < n;
}













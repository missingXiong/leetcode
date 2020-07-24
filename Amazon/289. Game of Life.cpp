vector<vector<int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, 
							{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
void gameOfLife(vector<vector<int>>& board)
{
	int m = board.size();
	int n = board[0].size();
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			check(board, m, n, i, j);
	
	update(board, m, n);
}

void check(vector<vector<int>>& board, int m, int n, int x, int y)
{
	// check its nbhs how many lives
	int count = 0;
	for(int k = 0; k < 8; k++)
	{
		int ix = x + dirs[k][0];
		int iy = y + dirs[k][1];
		if(ix >= 0 && ix < m && iy >= 0 && iy < n)
			if(board[ix][iy] == 1 || board[ix][iy] == -2) count++;
	}
	
	// mark live=>die as -2
	if(board[x][y] == 1 && (count > 3 || count < 2)) 
		board[x][y] = -2;
	// mark die=>live as 2
	else if(board[x][y] == 0 && count == 3)
		board[x][y] = 2;
}

void update(vector<vector<int>>& board, int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] == -2) board[i][j] = 0;
			if(board[i][j] == 2) board[i][j] = 1;
		}
	}
}
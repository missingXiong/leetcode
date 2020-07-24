

vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {1, -2}, 
							{2, -1}, {2, 1}, {-1, 2}, {1, 2}};
int minKnightMoves(int x, int y)
{
	if(x == 0 && y == 0) return 0;
	int step = 0;
	x = abs(x), y = abs(y);
	const int n = 400;
	vector<vector<int>> mat(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	mat[0][0] = 0;
	while(!q.empty())
	{
		step++;
		int size = q.size();
		while(size--)
		{
			auto pos = q.front(); q.pop();
			for(int i = 0; i < 8; i++)
			{
				int ix = pos.first + dirs[i][0];
				int iy = pos.second + dirs[i][1];
				if(ix == x && iy == y) return step;
				if(ix >= 0 && iy >= 0 && ix < n && iy < n && mat[ix][iy] == -1)
				{
					mat[ix][iy] = 0;
					q.emplace(ix, iy);
				}
			}
		}
		step++;
	}
	return -1;
}


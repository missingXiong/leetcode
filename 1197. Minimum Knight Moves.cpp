
vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {1, -2}, 
							{2, -1}, {2, 1}, {-1, 2}, {1, 2}};
int minKnightMoves(int x, int y)
{
	x = abs(x);
	y = abs(y);
	
	int steps = 0;
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	
	unordered_set<string> visited;
	visited.insert("0,0");
	while(!q.empty())
	{
		steps++;
		int size = q.size();
		while(size--)
		{
			auto pos = q.front(); q.pop();
			for(auto v : dir)
			{
				int ix = pos.first + v[0];
				int iy = pos.second + v[1];
				if(ix == x && iy == y) return steps;
				
				string s = to_string(ix) + "," + to_string(iy);
				if(ix >= 0 && iy >= 0 && !visited.count(s))
				{
					visited.insert(s);
					q.emplace(ix, iy);
				}
			}
		}
	}
	
	return steps;
}
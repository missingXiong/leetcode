class UnionFind
{
public:
	UnionFind(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		
        count = 0;
		parent = vector<int>(m * n);
		size = vector<int>(m * n, 0);
		
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int tid = i * n + j;
				parent[tid] = tid;
				if(grid[i][j] == 1)
				{
					size[tid] = 1;
					count++;
				}
			}
		}
	}		
	
	int find(int x)
	{
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}
	
	void join(int x, int y)
	{
		int root_x = find(x);
		int root_y = find(y);
		
		if(root_x != root_y)  // join by size
		{
			if(size[root_x] <= size[root_y])
			{
				parent[root_x] = root_y;
				size[root_y] += size[root_x];
			}
			else
			{
				parent[root_y] = root_x;
				size[root_x] += size[root_y];
			}
			count--;
		}
	}
	
	int queryCount() {return this->count;}
	int querySize(int p) {return this->size[p];}
	
private:
	int count;
	vector<int> parent;
	vector<int> size;
};

vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int largestIsland(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	
	UnionFind uf(grid);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == 1)
			{
				for(int k = 0; k < 4; k++)
				{
					int ix = i + dirs[k][0];
					int iy = j + dirs[k][1];
					
					if(ix >= 0 && ix < m && iy >= 0 && iy < n && grid[ix][iy] == 1)
					{
						uf.join(i * n + j, ix * n + iy);
					}
				}
			}
		}	
	}
	
	int ans = INT_MIN;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == 0)
			{
                unordered_set<int> check;
				for(int k = 0; k < 4; k++)
				{
					int ix = i + dirs[k][0];
					int iy = j + dirs[k][1];
					
					if(ix >= 0 && ix < m && iy >= 0 && iy < n && grid[ix][iy] == 1)
					{
						int parent = uf.find(ix * n + iy);
						check.insert(parent);
					}
				}
                
                int nums = 0;
                for(int parent : check)
                    nums += uf.querySize(parent);

                ans = max(ans, nums + 1);
			}
		}
	}
	
	return ans == INT_MIN ? m * n : ans;
}
















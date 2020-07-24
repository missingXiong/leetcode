/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
*/


// solution 1 : dfs
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

void dfs(vector<vector<char>>& grid, int x, int y, const int m, const int n)
{
	if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
		return;
	
	grid[x][y] = '0';
	// dfs 4 directions
	for(int i = 0; i < 4; i++)
		dfs(grid, x + dx[i], y + dy[i], m, n);
	
}

int numIslands(vector<vector<char>>& grid)
{
	if(grid.size() == 0) return 0;
	
	int count = 0;
	int m = grid.size();
	int n = grid[0].size();
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == '1')
			{
				count++;
				dfs(grid, i, j, m, n);
			}
		}
	}
	return count;
}

// solution 2 : union find
/* 
如何转化为连通域求解？ coordinates(x, y) => id = x * col + y which is unique
如何初始化？？？ count && parent
*/
class UnionFind
{
public:
	UnionFind(vector<vector<int>>& grid, int m, int n)
	{
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(grid[i][j] == '1') count++;
		
		parent = vector<int>(m * n);   // initialization
		for(int i = 0; i < m * n; i++)
			parent[i] = i;
	}
	
	int find(int x)
	{
		if(x == parent[x]) return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}
	
	void union(int x, int y)
	{
		int root_x = find(x);
		int root_y = find(y);
		if(root_x != root_y)
		{
			parent[root_x] = root_y;
			count--;
		}
	}
	
	int query() { return this->count; }
private:
	int count;
	vector<int> parent;
};

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
int numIslands(vector<vector<char>>& grid)
{
	if(grid.size() == 0) return 0;
	int m = grid.size();
	int n = grid[0].size();
	
	UnionFind uf = new UnionFind(grid, m, n);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == '1')
			{
				int id = i * n + j;
				for(int k = 0; k < 4; k++)
				{
					int tid = (i + dx[k]) * n + (j + dy[k]);
					if(tid >= 0 && tid < m * n && grid[i + dx[k]][j + dy[k]] == '1')
						uf.union(id, tid);
				}
			}
		}
	}
	return uf.query();
}































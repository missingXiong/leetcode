
// O((m + n)^2) + O(1)
vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	const int m = matrix.size();
	const int n = matrix[0].size();
	
	if(m == 0) return {};
	
	vector<int> ans;
	for(int s = 0; s <= m + n - 2; s++)
	{
		for(int i = 0; i <= s; i++)
		{
			int x = i;
			int y = s - x;
			
			if(s % 2 == 0) swap(x, y);
			
			if(x >= 0 && x < m && y >=0 && y < n)
				ans.push_back(matrix[x][y]);
		}
	}
	
	return ans;
}

// O(mn) + O(mn)
vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	if(matrix.size() == 0) return {};
	
	const int m = matrix.size();
	const int n = matrix[0].size();
	
	vector<vector<int>> dict(m + n - 1);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dict[i + j].push_back(matrix[i][j]);
		}
	}
	
	vector<int> ans;
	bool reverse = true;
	for(vector<int>& v : dict)
	{
		if(reverse) std::reverse(v.begin(), v.end());
		ans.insert(ans.end(), v.begin(), v.end());
		reverse = !reverse;
	}
	
	return ans;
}


vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0) return {};
	
	const int m = matrix.size();
	const int n = matrix[0].size();
	
	int row = 0, col = 0;
	int clockwise = 1;
	int total = m * n;
	vector<int> ans;
	
	while(total)
	{
		while(row >= 0 && row < m && col >= 0 && col < n)
		{
			ans.push_back(matrix[row][col]);
			total--;
			row = row - clockwise;
			col = col + clockwise;
		}
		
		if(clockwise == 1)
		{
			if(col >= n) 
			{
				// 冲出右边界
				row = row + 2;
				col = n - 1;
			}
            else  // 冲出上边界
                row = 0;
		}
		else
		{
			if(row >= m)
			{
				// 冲出下边界
				row = m - 1;
				col = col + 2;
			}
            else   // 冲出左边界
                col = 0;
		}
		
		// 改变方向
		clockwise = clockwise * (-1);
	}
	
	return ans;
}




















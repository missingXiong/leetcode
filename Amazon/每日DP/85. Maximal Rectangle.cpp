
221. Maximal Square
int maximalSquare(vector<vector<char>>& matrix)
{
	if(matrix.size() == 0) return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	
	int ans = 0;
	vector<vector<int>> dp(2, vector<int>(n + 1, 0));
	
	int old = 0, now = 0;
	for(int i = 1; i <= m; i++)
	{
		old = now;
		now = 1 - now;
		for(int j = 1; j <= n; j++)
		{
			if(matrix[i - 1][j - 1] == '1')
			{
				dp[now][j] = min(dp[old][j - 1], min(dp[old][j], dp[now][j - 1])) + 1;
				ans = max(ans, dp[now][j]);
			}
		}
	}
	return ans * ans;
}

84. Largest Rectangle in Histogram
/*
Brute Force:
A simple solution is to one by one consider all bars as starting points and calculate 
area of all rectangles starting with every bar. Finally return maximum of all possible areas. 
Time complexity of this solution would be O(n^2).
*/
int largestRectangleArea(vector<int>& heights)
{
	int maxArea = 0;
	for(int curr = 0; curr < heights.size(); curr++)
	{
		if(curr == heights.size() - 1 || heights[curr] > heights[curr + 1])
		{
			int minHeight = INT_MAX;
			for(int idx = curr; idx >= 0; idx--)
			{
				minHeight = min(minHeight, heights[idx]);
				maxArea = max(maxArea, minHeight * (curr - idx + 1));
			}
		}
	}
	return maxArea;
}

/*
计算以各个bar，以次高度向两边拓展，找到左右两边低于此高度的地方
*/
int largestRectangleArea(vector<int>& heights)
{
	int maxArea = 0;
	for(int curr = 0; curr < heights.size(); curr++)
	{
		int left = curr - 1, right = curr + 1;
		for(; left >= 0; left--)
			if(heights[left] < heights[curr]) break;
		for(; right < heights.size(); right++)
			if(heights[right] < heights[curr]) break;
		maxArea = max(maxArea, heights[curr] * (right - left - 1));
	}
	return maxArea;
}

// monotonic stack : strictly increasing
int largestRectangleArea(vector<int>& heights)
{
	stack<int> stk;    // index of elements
	int index = 0;
	int maxArea = 0;
	heights.push_back(-1);
	
	while(index < heights.size())
	{
		if(stk.empty() || heights[index] > heights[stk.top()])
			stk.push(index++);
		else
		{
			int peek_index = stk.top(); stk.pop();
			int left_most = stk.empty() ? -1 : stk.top();
			maxArea = max(maxArea, heights[peek_index] * (index - left_most - 1));
		}
	}
	heights.pop_back();
	return maxArea;
}


85. Maximal Rectangle
int maximalRectangle(vector<vector<char>>& matrix)
{
	if(matrix.size() == 0) return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	
	int ans = 0;
	vector<vector<pair<int, int>>> dp(m + 1, vector<pair<int, int>>(n + 1, {0, 0}));
	
	
}
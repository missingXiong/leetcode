

int largestRectangleArea(vector<int>& heights)
{
	heights.insert(heights.begin(), 0);
	heights.push_back(0);
	int size = heights.size();
	int maxArea = 0;
	stack<int> stk;
	stk.push(0);
	for(int i = 1; i < size; i++)
	{
		while(!stk.empty() && heights[i] < heights[stk.top()])
		{
			int index = stk.top(); stk.pop();
			maxArea = max(maxArea, heights[index] * (i - stk.top() - 1));
		}
		stk.push(i);
	}
	
	return maxArea;
}
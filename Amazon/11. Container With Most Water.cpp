

int maxArea(vector<int>& height)
{
	int size = height.size();
	int maxArea = 0;
	int left = 0, right = size - 1;
	while(left < right)
	{
		if(height[left] < height[right])
		{
			maxArea = max(maxArea, height[left] * (right - left));
			left++;
		}
		else
		{
			maxArea = max(maxArea, height[right] * (right - left));
			right--;
		}
	}
	return maxArea;
}
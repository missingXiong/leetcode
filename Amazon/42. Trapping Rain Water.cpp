
/*
Brute Force:
for i = 0 to n
	r[i] = min(max(h[0 ~ i]), max(h[i ~ n - 1])) - h[i];
*/
int trap(vector<int>& height)
{
	int size = height.size();
	if(size == 0) return 0;
	
	int ans = 0;
	auto sit = height.begin();
	auto eit = height.end();
	for(int i = 0; i < size; i++)
	{
		int l = *max_element(sit, sit + i + 1);
		int r = *max_element(sit + i, eit);
		ans += min(l, r) - height[i];
	}
	return ans;
}

/*
从Brute Force可以看出，对于每一个元素我们都要求出它左右两边的最大值
*/
int trap(vector<int>& height)
{
	int n = height.size();
	// 预先求出左右两边的最大值
	vector<int> l(n);
	vector<int> r(n);
	for(int i = 0; i < n; i++)
		l[i] = i == 0 ? height[i] : max(l[i - 1], height[i]);
	for(int i = n - 1; i >= 0; i--)
		r[i] = i == n - 1 ? height[i] : max(r[i + 1], height[i]);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += min(l[i], r[i]) - height[i];
	return ans;
}


int trap(vector<int>& height)
{
	int size = height.size();
	if(size == 0) return 0;
	
	int left = 0, right = size - 1;
	int ans = 0;
	while(left < right)
	{
		if(height[left] <= height[right])
		{
			if(height[left] > height[left + 1])
			{
				ans += height[left] - height[left + 1];
				height[left + 1] = height[left];
			}
				
			left++;	
		}
		else
		{
			if(height[right] > height[right - 1])
			{
				ans += height[right] - height[right - 1];
				height[right - 1] = height[right];
			}
			right--;
		}
	}
	return ans;
}



























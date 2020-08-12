

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
	// find the first element which greater or equal than x
	int lo = 0, hi = arr.size() - 1;
	int index = -1;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] >= x)
		{
			index = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	
	vector<int> ans;
	// if elements in array less than x
	if(index == -1)
		ans.insert(ans.begin(), arr.begin() + (arr.size() - k), arr.end());
	else
	{
		int left = index - 1, right = index;
		while(k--)
		{
			if(left >= 0 && right < arr.size())
			{
				if(abs(arr[left] - x) <= abs(arr[right] - x))
					left--;
				else
					right++;
			}
			else
				left >= 0 ? left-- : right++;
		}
		ans.insert(ans.begin(), arr.begin() + left + 1, arr.begin() + right);
	}
	return ans;
}
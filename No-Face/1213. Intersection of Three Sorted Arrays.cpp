
// two pointers
vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
	vector<int> v = intersection(arr1, arr2);
	return intersection(v, arr3);
}

vector<int> intersection(vector<int>& arr1, vector<int>& arr2)
{
	int i = 0, j = 0;
	vector<int> ans;
	while(i < arr1.size() && j < arr2.size())
	{
		if(arr1[i] == arr2[j])
		{
			ans.push_back(arr1[i]);
			i++; j++;
		}
		else
			arr1[i] < arr2[j] ? i++ : j++;
	}
	return ans;
}

// binary search
vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
	vector<int> ans;
	for(int val : arr1)
	{
		if(search(arr2, val) && search(arr3, val))
			ans.push_back(val);
	}
	
	return ans;
}


bool search(vector<int>& arr, int target)
{
	int low = 0, high = arr.size() - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(arr[mid] == target)
			return true;
		else if(arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	return false;
}
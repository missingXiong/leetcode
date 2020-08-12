

int maxSubarraySumCircular(vector<int>& A)
{
	vector<int> arr(A.begin(), A.end());
	arr.insert(arr.end(), A.begin(), A.end());
	
	int j = 0;
	int curr_sum = 0, max_sum = INT_MIN;
	for(int i = 0; i < arr.size(); i++)
	{
		if(curr_sum < 0)
		{
			j = i;
			curr_sum = 0;
		}
	
		if(i - j + 1 > A.size()) 
		{
			curr_sum -= arr[j++];
			while(j < i)
			{
				if(arr[j] < 0) curr_sum -= arr[j++];
			}
		}
		
		
		
		curr_sum += arr[i];
		max_sum = max(max_sum, curr_sum);
	}
	
	return max_sum;
}
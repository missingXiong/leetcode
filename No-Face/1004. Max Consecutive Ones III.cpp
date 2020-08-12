
// slide window
int longestOnes(vector<int>& A, int k)
{
	int ans = 0;
	int i = 0, changes = 0;
	for(int j = 0; j < A.size(); j++)
	{
		if(A[j] == 0) changes++;
		
		while(changes > k)
		{
			if(A[i] == 0) changes--;
			i++;
		}
		
		ans = max(ans, j - i + 1);
	}
	
	return ans;
}
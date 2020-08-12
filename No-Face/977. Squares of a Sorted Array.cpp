vector<int> sortedSquares(vector<int>& A)
{
	vector<int> ans(A.size());
	int i = 0, j = A.size() - 1;
	for(int k = A.size() - 1; k >= 0; k--)
	{
		if(A[i] * A[i] <= A[j] * A[j])
		{
			ans[k] = A[j] * A[j];
			j--;
		}
		else
		{
			ans[k] = A[i] * A[i];
			i++;
		}
	}
	return ans;
}
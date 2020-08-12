
// same: longest increasing subsequence
int longestArithSeqLength(vector<int>& A)
{
	int size = A.size();
	int minval = INT_MAX, maxval = INT_MIN;
	for(int num : A)
	{
		minval = min(minval, num);
		maxval = max(maxval, num);
	}
	
	int maxDiff = maxval - minval;
	int ans = 0;
	vector<vector<int>> dp(size, vector<int>(2 * maxDiff + 1, 0));  // avoid negative diff
	for(int i = 1; i < size; i++)
	{
		for(int j = 0; j < i; j--)
		{
			int diff = A[i] - A[j];
			dp[i][diff + maxDiff] = dp[j][diff + maxDiff] + 1;
			ans = max(ans, dp[i][diff + maxDiff]);
		}
	}
	return ans + 1;
}

// we can find that the space complexity is pretty high, how to eliminate maxDiff????
int longestArithSeqLength(vector<int>& A)
{
	int size = A.size();
	int ans = 0;
	vector<unordered_map<int, int>> dp(size);
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < i; j++)
		{
			int diff = A[i] - A[j];
			dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
			ans = max(ans, dp[i][diff]);
		}
	}
	
	return ans;
}



























vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
{
    vector<vector<int>> ans;
	int i = 0, j = 0;
	while(i < A.size() && j < B.size())
	{
		int minVal = max(A[i][0], B[j][0]);
		int maxVal = min(A[i][1], B[j][1]);
		
		if(minVal <= maxVal)  // intersection exists
            ans.push_back({minVal, maxVal});
		
		if(A[i][1] < B[j][1]) i++;
        else j++;
	}
	
	return ans;
}
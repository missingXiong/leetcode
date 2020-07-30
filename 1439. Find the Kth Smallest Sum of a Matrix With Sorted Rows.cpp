int kthSmallest(vector<vector<int>>& mat, int k)
{
	int m = mat.size();
	int n = mat[0].size();
	
	vector<int> ans(mat[0]);
	
	for(int i = 1; i < m; i++)
	{
		multiset<int> st;
		for(int x : ans)
		{
			for(int y : mat[i])
				st.insert(x + y);
		}
		
		ans.assign(st.begin(), st.end());
		ans.resize(min(k, ans.size()));
	}
	
	return ans.back();
}
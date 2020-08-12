vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
	std::sort(people.begin(), people.end(), [](const vector<int>& lhv, const vector<int>& rhv)
	{
		if (lhv[0] != rhv[0])
			return lhv[0] > rhv[0];
		else
			return lhv[1] < rhv[1];
	});
	
	vector<vector<int>> ans(people.begin(), people.end());
	for (int i = 0; i < ans.size(); i++)     // insertion sort
	{
		int j = ans[i][1];
		if (j == i) continue;
		
		vector<int> curr = ans[i];
		for (int k = i - 1; k >= j; k--)
			swap(ans[k], ans[k + 1]);
		ans[j] = curr;
	}
	return ans;
}


vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
	std::sort(people.begin(), people.end(), [](const vector<int>& lhv, const vector<int>& rhv)
	{
		if (lhv[0] != rhv[0])
			return lhv[0] > rhv[0];
		else
			return lhv[1] < rhv[1];
	});
	
	list<vector<int>> li;
	for(auto& p: people)
	{   
		auto pos = li.begin();
		std::advance(pos, p[1]);  
		li.insert(pos, p);
	}
	return vector<vector<int>>(li.begin(), li.end());
}
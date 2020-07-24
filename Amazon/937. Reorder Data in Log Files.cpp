

void moveZeroes(vector<int>& nums)
{
	int j = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] != 0)
			swap(nums[j++], nums[i]);
	}
}

vector<string> reorderLogFiles(vector<string>& logs)
{
	auto compare = [](const string& lhs, const string& rhs)
		{
			int pos1 = lhs.find(" ");
			int pos2 = rhs.find(" ");
			string sub1 = lhs.substr(pos1 + 1, lhs.length() - (pos1 + 1));
			string sub2 = rhs.substr(pos2 + 1, rhs.length() - (pos2 + 1));
			return sub1 >= sub2;
		};
	priority_queue<string, vector<string>, decltype(compare)> pq(compare);
	vector<string> digitLogs;
	for(int i = 0; i < logs.size(); i++)
	{
		int pos = logs[i].find(" ");
		if(isalpha(logs[i][pos + 1]))
			pq.push(logs[i]);
		else
			digitLogs.push_back(logs[i]);
	}
	
	vector<string> ans;
	while(!pq.empty())
	{
		ans.push_back(pq.top()); 
		pq.pop();
	}
	
	for(string s : digitLogs) ans.push_back(s);
	return ans;
}
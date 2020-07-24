

vector<int> countSteppingNumbers(int low, int high)
{
	vector<int> ans;
	if(low == 0) ans.push_back(0);  // 高位为0的情况单独考虑
	for(int j = 1; j <= 9; j++)
	{
		string curr;
		curr += (j + '0');
		DFS(low, high, ans, curr);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

void DFS(int low, int high, vector<int>& ans, string& curr)
{
	long long num = stoi(curr);
	if(num >= low && num <= high)
		ans.push_back(num);
	if(num > high) return;
	
	char pre = curr.back();
	if(pre - 1 >= '0')
	{
		curr.push_back(pre - 1);
		DFS(low, high, ans, curr);
		curr.pop_back();
	}
	if(pre + 1 <= '9')
	{
		curr.push_back(pre + 1);
		DFS(low, high, ans, curr);
		curr.pop_back();
	}
}
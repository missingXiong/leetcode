
vector<vector<char>> dic = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, 
						{'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, 
						{'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
vector<string> letterCombinations(string digits)
{
	vector<string> ans;
	if(digits.length() == 0) return ans;
	string curr;
	dfs(digits, 0, curr, ans);
	return ans;
}

void dfs(string& digit, int start, string& curr, vector<string>& ans)
{
	if(start == digit.length())
	{
		ans.push_back(curr);
		return;
	}
	
	int num = digit[start] - '0';
	for(int i = 0; i < dic[num].size(); i++)
	{
		curr.push_back(dic[num][i]);
		dfs(digit, start + 1, curr, ans);
		curr.pop_back();
	}
}
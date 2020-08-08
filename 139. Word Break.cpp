bool wordBreak(string s, vector<string>& wordDict)
{
	if (s.length() == 0) return false;
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	unordered_map<string, bool> memo;
	return search(dict, memo, s);
}

bool search(unordered_set<string>& dict, unordered_map<string, bool>& memo, string& s)
{
	if (dict.count(s)) memo[s] = true;
	if (memo.count(s)) return memo[s];
	
	for (int i = 1; i <= s.length(); i++)
	{
		string left = s.substr(0, i);
		string right = s.substr(i);
		if (dict.count(left) && search(dict, memo, right))
		{
			return memo[s] = true;
		}
	}
	return memo[s] = false;
}
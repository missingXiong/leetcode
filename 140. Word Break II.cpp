vector<string> wordBreak(string s, vector<string>& wordDict)
{
	if (s.length() == 0) return {};
	
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	unordered_map<string, vector<string>> memo;
	return search(dict, memo, s);
}

vector<string> search(unordered_set<string>& dict, unordered_map<string, vector<string>>& memo, string& s)
{
	if (memo.count(s)) return memo[s];
	
	vector<string> temp;
	if (dict.count(s))
		temp.push_back(s);
	
	for (int i = 1; i < s.length(); i++)
	{
		string left = s.substr(0, i);
		string right = s.substr(i);
		if (dict.find(left) == dict.end()) continue;
		vector<string> v = search(dict, memo, right);
		combine(left, v, temp);
	}
	
	memo[s] = temp;
	return temp;
}

void combine(string& s, vector<string>& v, vector<string>& temp)
{
	for (string& str : v)
	{
		temp.push_back(s + " " + str);
	}
}
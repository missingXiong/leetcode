

vector<string> wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	return canBreak(s, dict);
}

unordered_map<string, vector<string>> memo;
vector<string> append(string& word, vector<string>& suffix)
{
	vector<string> res;
	for(const string& s : suffix)
		res.push_back(word + " " + s);
	return res;
}

vector<string> canBreak(string& s, unordered_set<string>& dict)
{
	if(memo.count(s)) return memo[s];
	
	vector<string> ans;
	if(dict.count(s))
		ans.push_back(s);
	for(int i = 1; i < s.length(); i++)
	{
		string left = s.substr(0, i);
		string right = s.substr(i, s.length() - i);
		if(!dict.count(left)) continue;
		vector<string> left_ans = append(left, canBreak(right, dict));
		ans.insert(ans.end(), left_ans.begin(), left_ans.end());
	}
	memo[s] = ans;
	return memo[s];
}
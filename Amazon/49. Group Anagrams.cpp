

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> m;
	for(string& word : strs)
	{
		string s = word;
		sort(s.begin(), s.end());
		m[s].push_back(word);
	}
	
	for(auto& p : m)
		ans.push_back(p.second);
	return ans;
}
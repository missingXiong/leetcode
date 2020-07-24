

vector<string> findRepeatedDnaSequences(string s)
{
	if(s.length() < 10) return {};
	int left = 0;
	unordered_map<string, int> counts;
	vector<string> ans;
	for(; left < s.length() - 9; left++)
	{
		string substr = s.substr(left, 10);
		counts[substr]++;
		if(counts[substr] == 2) ans.push_back(substr);
	}
	return ans;
}
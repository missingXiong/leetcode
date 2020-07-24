

vector<string> restoreIpAddresses(string s)
{
	vector<string> ans;
	string curr;
	DFS(s, ans, 0, curr, 0);
	return ans;
}

void DFS(const string& s, vector<string>& ans, int start, string curr, int parts)
{
	if(parts > 4) return;
	
	if(start == s.length() && parts == 4)
	{
		curr.erase(curr.end() - 1);
		ans.push_back(curr);
		return;
	}
	
	for(int i = start; i < s.length(); i++)
	{
		if(s[start] == '0' && i > start) return;
		string substr = s.substr(start, i - start + 1);
		if(stoi(substr) > 255) return;
		DFS(s, ans, i + 1, curr + substr + '.', parts + 1);
	}
}
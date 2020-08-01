string customSortString(string S, string T)
{
	unordered_map<char, int> dict;
	for(char c : T)
		dict[c]++;
	
	string ans = "";
	for(char c : S)
	{
		if(dict.count(c))
		{
			ans += string(dict[c], c);
			dict.erase(c);
		}
	}
	
	for(auto p : dict)
	{
		ans += string(p.second, p.first);
	}
	
	return ans;
}


string customSortString(string S, string T)
{
	unordered_map<char, int> dir;
	for(int i = 0; i < S.length(); i++)
		dir[S[i]] = i + 1;
	
	sort(T.begin(), T.end(), [&dir](const char lhc, const char rhc) {return dir[lhc] < dir[rhc];});
	return T;
}

// recursion O(n^3)
bool checkValidString(string s)
{
	return dfs(s, 0, 0);
}

bool dfs(string& s, int start, int val)
{
	if (val < 0) return false;
	
	if (start == s.length()) 
		return val == 0;
	
	if (s[start] == '*')
		return dfs(s, start + 1, val) || dfs(s, start + 1, val + 1) || dfs(s, start + 1, val - 1);
	else if (s[start] == '(')
		return dfs(s, start + 1, val + 1);
	else
		return dfs(s, start + 1, val - 1);
}



string decodeString(string s)
{
	int pos = 0;
	return helper(pos, s);
}

string helper(int& pos, string s)
{
	int num = 0;
	string word;
	for(; pos < s.length(); pos++)
	{
		if(isdigit(s[pos]))
			num = num * 10 + (s[pos] - '0');
		else if(isalpha(s[pos]))
			word += s[pos];
		else if(s[pos] == '[')
		{
			string str = helper(++pos, s);
			for(int i = 0; i < num; i++)
				word += str;
			num = 0;
		}
		else if(s[pos] == ']')
			return word;
	}
	return word;
}
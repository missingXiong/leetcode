

bool isOpen(const char& c)
{
	if(c == '(' || c == '{' || c == '[')
		return true;
	else return false;
}

bool isMatch(const char& c1, const char& c2)
{
	if(c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']')
		return true;
	else return false;
}

bool isValid(string s) 
{
	stack<char> stk;
	for(const char c : s)
	{
		if(stk.empty() || isOpen(c))
			stk.push(c);
		else
		{
			if(isMatch(stk.top(), c))
				stk.pop();
			else
				stk.push(c);
		}
	}
	return stk.empty();
}
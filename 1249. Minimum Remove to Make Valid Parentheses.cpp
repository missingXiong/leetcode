
template <class ForwardIterator, class T>
  ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val)
{
	ForwardIterator result = first;
	while (first != last) 
	{
		if (!(*first == val)) 
		{
			*result = *first;
			++result;
		}
		++first;
	}
	return result;
}


string minRemoveToMakeValid(string s)
{
	stack<int> stk;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(') 
			stk.push(i);
		if(s[i] == ')')
		{
			if(!stk.empty() && s[stk.top()] == '(')
				stk.pop();
			else
				stk.push(i);
		}
	}
	
	while(!stk.empty())
	{
		int index = stk.top(); stk.pop();
		s[index] = '*';
		// s.erase(index, 1);
	}
	
	s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
	
	return s;
}


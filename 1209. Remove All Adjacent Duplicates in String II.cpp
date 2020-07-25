
// O(n * n / k)
string removeDuplicates(string s, int k)
{
    bool changed = false;

	do
	{
		changed = false;
        int duplicates = 1;
		for(int i = 1; i < s.length(); i++)
		{
			if(s[i] == s[i - 1])
			{
				if(++duplicates == k)
				{
					changed = true;
					int j = i;
					while(duplicates--)
						s[j--] = '*';
					duplicates = 1;
				}
			}
			else
				duplicates = 1;
		}
		s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
	}while(changed);
		
	return s;
}


// O(n)
string removeDuplicates(string s, int k)
{	
	stack<pair<char, int>> stk;
	stk.emplace('#', 1);
	for(char c : s)
	{
		if(c == stk.top().first)
		{
			if(stk.top().second == k - 1)
			{
				while(stk.top().first == c)
					stk.pop();
			}
			else
				stk.emplace(c, stk.top().second + 1);
		}
		else
			stk.emplace(c, 1);
	}
	
	string ans = "";
	while(!stk.empty())
	{
		ans.push_back(stk.top().first);
		stk.pop();
	}
	
	ans.pop_back();
	std::reverse(ans.begin(), ans.end());
	return ans;
}


string removeDuplicates(string s, int k)
{
    stack<pair<char, int>> stk;
	stk.emplace('#', 1);
	
	for(char c : s)
	{
		if(stk.top().first != c)
			stk.emplace(c, 1);
		else if(stk.top().first == c && ++stk.top().second == k)
			stk.pop();
	}
	
	string ans = "";
	while(!stk.empty())
	{
		ans += string(stk.top().second, stk.top().first);
		stk.pop();
	}
	
	ans.pop_back();
	std::reverse(ans.begin(), ans.end());
	return ans;
}


string removeDuplicates(string s, int k)
{
	vector<pair<char, int>> stack;
	stack.emplace_back('#', 1);
	
	for(char c : s)
	{
		if(stack.back().first != c) 
			stack.emplace_back(c, 1);
		else if(stack.back().first == c && ++stack.back().second == k)
			stack.pop_back();
	}
	
	string ans = "";
	for(int i = 1; i < stack.size(); i++)
	{
		ans += string(stack[i].second, stack[i].first);
	}
	
	return ans;
}

// two pointers
string removeDuplicates(string s, int k)
{
	vector<int> cnt(s.length(), 0);
	int j = 0;
	for(int i = 0; i < s.length(); i++, j++)
	{
		s[j] = s[i];
		if(j > 0 && s[j] == s[j - 1])
			cnt[j] = cnt[j - 1] + 1;
		else
			cnt[j] = 1;
		
		if(cnt[j] == k) j -= k;
	}
	
	return s.substr(0, j);
}



























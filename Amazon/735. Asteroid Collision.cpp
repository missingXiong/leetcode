

vector<int> asteroidCollision(vector<int>& asteroids)
{
	if(asteroids.size() == 0) return {};
	stack<int> stk;
	
	for(int scale : asteroids)
	{
		if(stk.empty() || stk.top() < 0)
			stk.push(scale);
		else
		{
			if(scale > 0) stk.push(scale);
			else
			{
				while(!stk.empty() && stk.top() > 0 && stk.top() < -scale)
					stk.pop();
				
				if(!stk.empty() && stk.top() >= -scale)
				{
					if(stk.top() == -scale) stk.pop();
					continue;
				}
				else
					stk.push(scale);
			}
		}
	}
	
	vector<int> ans;
	while(!stk.empty())
	{
		ans.push_back(stk.top());
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> asteroidCollision(vector<int>& asteroids)
{
	vector<int> stk; // simulate stack
	for(int i : asteroids)
	{
		while(!stk.empty() && stk.back() > 0 && stk.back() < -i)
			stk.pop_back();
		
		if(!stk.empty() && i < 0 && stk.back() >= -i)
		{
			if(stk.back() == -i) stk.pop_back();
			continue;
		}
		else
			stk.push_back(i);
	}
	return stk;
}
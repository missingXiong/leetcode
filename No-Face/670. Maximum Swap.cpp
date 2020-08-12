int maximumSwap(int num)
{
	string snum = to_string(num);
	int size = snum.size();
	vector<int> bigger(size, -1);
	stack<int> stk;
	// need find the farest greater than curr number(not equal)
	for (int i = size - 1; i >= 0; i--)
	{
		while(!stk.empty() && snum[i] > snum[stk.top()]) 
			stk.pop();
		if (!stk.empty() && snum[i] != snum[stk.top()]) bigger[i] = stk.top();
		if (stk.empty()) stk.push(i);
	}

    
	for (int i = 0; i < size; i++)
	{
		if (bigger[i] != -1)
		{
			swap(snum[i], snum[bigger[i]]);
            break;
		}
	}
	
	return stoi(snum);
}
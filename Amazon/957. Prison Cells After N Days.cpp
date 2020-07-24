
// time complexity
vector<int> prisonAfterNDays(vector<int>& cells, int N)
{
	int size = cells.size();
	vector<vector<int>> rolling(2, vector<int>(size, 0));
	for(int i = 0; i < size; i++)
		rolling[0][i] = cells[i];
	int old = 0, now = 0;
	for(int k = 1; k <= N; k++)
	{
		old = now; now = 1 - now;
		rolling[now][0] = rolling[now][size - 1] = 0;
		for(int i = 1; i < size - 1; i++)
		{
			if(rolling[old][i - 1] == rolling[old][i + 1])
				rolling[now][i] = 1;
			else rolling[now][i] = 0;
		}
	}
	return rolling[now];
}

/*
由于题中给出的N过大，因此算法应该保证和N的关系不大
那么一定是存在某种规律
*/
vector<int> prisonAfterNDays(vector<int>& cells, int N)
{
	vector<int> fc, curr(cells.size(), 0);
	for(int cycle = 1; N-- > 0; cells = curr, cycle++)
	{
		for(int i = 1; i < cells.size() - 1; i++)
			curr[i] = cells[i - 1] == cells[i + 1];
		if(cycle == 1) fc = curr;
		else if(curr == fc) N %= (cycle - 1);
	}
	return curr;
	
	/*
	int n = cells.size(), cycle = 0;
	vector<int> cur(n, 0), direct;
	while(N-- > 0) {
		for(int i = 1; i < n - 1; ++i) cur[i] = cells[i - 1] == cells[i + 1];
		if(direct.empty()) direct = cur;
		else if(direct == cur) N %= cycle;

		++cycle;
		cells = cur;
	}
	return cur;
	*/
}
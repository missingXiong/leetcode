
// expand by station
int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
{
	int size = routes.size();
	unordered_map<int, vector<int>> station_buses;
	for (int i = 0; i < size; i++)
	{
		for (int station : routes[i])
			station_buses[station].push_back(i);
	}
	
	vector<bool> visited(size, false);
	queue<int> q;
	q.push(S);
	
	int step = 0;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int curr = q.front(); q.pop();
			if(curr == T) return step;
			for(int bus : station_buses[curr])
			{
				if(visited[bus]) continue;
				
				visited[bus] = true;
				for(int nxt : routes[bus])
				{
					if(nxt != curr) q.push(nxt);
				}
			}
		}
		
		step++;
	}
	
	return -1;
}

// expand by bus-lines
int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
{
        if(S == T) return 0;
        	int n = routes.size();
	unordered_set<int> target;
	unordered_map<int, vector<int>> station_buses;
	for (int i = 0; i < n; i++)
	{
		for (int station : routes[i])
		{
			if(station == T) target.insert(i);
			station_buses[station].push_back(i);
		}
	}
	
	vector<bool> visited(n, false);
	queue<int> q;
	for(int bus : station_buses[S]) q.push(bus);
	
	int step = 1;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int curr = q.front(); q.pop();
			if(visited[curr]) continue;
			if(target.count(curr)) return step;
			
			visited[curr] = true;
			// which lines we can reach from curr line
			unordered_set<int> lines;
			for(int station : routes[curr])
			{
				for(int line : station_buses[station])
				{
					if(!visited[line]) lines.insert(line);
				}
			}
			
			for(int line : lines) q.push(line);
		}
		
		step++;
	}
	
	return -1;
}
























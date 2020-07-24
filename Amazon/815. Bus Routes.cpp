

int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
{
	if(S == T) return 0;
	unordered_map<int, vector<int>> to_routes;  // stop => routes
	for(int i = 0; i < routes.size(); i++)
	{
		for(int stop : routes[i])
			to_routes[stop].push_back(i);
	}
	
	unordered_set<int> dest_routes(to_routes[T].begin(), to_routes[T].end());
	unordered_set<int> visited_routes(to_routes[S].begin(), to_routes[S].end());
	unordered_set<int> visited_stops;
	visited_stops.insert(S);
	queue<int> q;
	for(int bus : to_routes[S])
		q.push(bus);
	int step = 1;
	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int route = q.front(); q.pop();
			for(int stop : routes[route])
			{
				if(stop == T) return step;
				
				if(visited_stops.count(stop)) continue;
				visited_stops.insert(stop);
				
				for(int bus : to_routes[stop])
				{
					if(!visited_routes.count(bus))
					{
						q.push(bus);
						visited_routes.insert(bus);
					}
				}
			}
		}
		step++;
	}
	
	return -1;
}
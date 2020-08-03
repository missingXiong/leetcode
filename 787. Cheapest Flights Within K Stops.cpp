
// bfs
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    vector<vector<pair<int, int>>> graph(n);
	for(auto station : flights)
		graph[station[0]].emplace_back(station[1], station[2]);
	
	queue<pair<int, int>> q;
	q.emplace(src, 0);
	
	int ans = INT_MAX;
	while(!q.empty() && K-- > -1)
	{
		int size = q.size();
		while(size--)
		{
			auto stop = q.front(); q.pop();
			for(auto flight : graph[stop.first])
			{
				int nxt = flight.first;
				int price = flight.second;
				if(nxt == dst) ans = min(ans, stop.second + price);
				if(price + stop.second < ans) q.emplace(nxt, price + stop.second);
			}
		}
	}
	
	return ans == INT_MAX ? -1 : ans;
}

// dfs
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    vector<vector<pair<int, int>>> graph(n);
	for(auto station : flights)
		graph[station[0]].emplace_back(station[1], station[2]);
	
	int ans = INT_MAX;
	DFS(graph, src, dst, K + 1, 0, ans);
	return ans == INT_MAX ? -1 : ans;
}

void DFS(vector<vector<pair<int, int>>>& graph, int src, int dst, int steps, int curr_price, int& ans)
{
	if(src == dst)
	{
		ans = min(ans, curr_price);
		return;
	}
	
	if(steps == 0) return;
	
	for(auto flight : graph[src])
	{
		int nxt = flight.first;
		int price = flight.second;
		if(curr_price + price >= ans) continue;
		DFS(graph, nxt, dst, steps - 1, curr_price + price, ans);
	}
}


// bellman-ford (DP)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
	vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));
	for(int i = 0; i <= K + 1; i++) dp[i][src] = 0;
	
	for(int i = 1; i <= K + 1; i++)
	{
		for(auto flight : flights)
		{
			int start = flight[0];
			int end = flight[1];
			int price = flight[2];
			
			if(dp[i - 1][start] != INT_MAX)
				dp[i][end] = min(dp[i][end], dp[i - 1][start] + price);
		}
	}
	
	return dp[K + 1][dst] == INT_MAX ? -1 : dp[K + 1][dst];
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
	vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
	dp[0][src] = dp[1][src] = 0;
	
	int old = 0, now = 0;
	for(int i = 1; i <= K + 1; i++)
	{
		old = now;
		now = 1 - now;
		
		for(auto flight : flights)
		{
			int start = flight[0];
			int end = flight[1];
			int price = flight[2];
			
			if(dp[old][start] != INT_MAX)
				dp[now][end] = min(dp[now][end], dp[old][start] + price);
		}
	}
	
	return dp[now][dst] == INT_MAX ? -1 : dp[now][dst];
}
	






















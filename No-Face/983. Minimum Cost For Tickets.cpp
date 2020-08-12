int mincostTickets(vector<int>& days, vector<int>& costs)
{
	vector<int> dp(366, 0);
	unordered_set<int> set;
	for(int day : days) set.insert(day);
	
	for(int i = 1; i < 366; i++)
	{
		if(set.find(i) == set.end()) 
			dp[i] = dp[i - 1];
		else
		{
			dp[i] = min({dp[max(i - 1, 0)] + costs[0], dp[max(i - 7, 0)] + costs[1], dp[max(i - 30, 0)] + costs[2]});
		}
	}
	
	return dp[365];
}



























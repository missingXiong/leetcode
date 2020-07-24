
int maxProfit(vector<int>& prices)
{
	int best = 0, curr = 0;
	for(int i = 1; i < prices.size(); i++)
	{
		curr += prices[i] - prices[i - 1];
		best = max(best, curr);
		if(curr < 0) curr = 0;
	}
	return best;
}

int maxProfit(vector<int>& prices)
{
	
}
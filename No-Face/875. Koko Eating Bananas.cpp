int minEatingSpeed(vector<int>& piles, int H)
{
	int low = 1;
	int high = *max_element(piles.begin(), piles.end());
    
	int ans = 0;
	while(low <= high)
	{
		int middle = low + (high - low) / 2;
		if(hoursToEat(middle, piles) <= H)
        {
            ans = middle;
            high = middle - 1;
        }
		else
			low = middle + 1;
	}
	return ans;
}


int hoursToEat(int speed, vector<int>& piles)
{
	int hours = 0;
	for(int pile : piles)
		hours += pile / speed + (pile % speed ? 1 : 0);
	return hours;
}
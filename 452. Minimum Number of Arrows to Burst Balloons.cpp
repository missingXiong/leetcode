int findMinArrowShots(vector<vector<int>>& points)
{
    if (points.size() == 0) return 0;
	sort(points.begin(), points.end(), 
	[](const vector<int>& lhv, const vector<int>& rhv) 
		{
			if (lhv[0] != rhv[0])
				return lhv[0] < rhv[0]; 
			else
				return lhv[1] < rhv[1];
		});
	
	int count = 1, minEnd = points[0][1];
	for (int i = 1; i < points.size(); i++)
	{
		if (minEnd < points[i][0])
		{
			count++;
			minEnd = points[i][1];
		}
		else
			minEnd = min(minEnd, points[i][1]);
	}
	return count;
}

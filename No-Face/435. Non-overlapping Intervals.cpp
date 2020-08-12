int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
	if (intervals.size() == 0) return 0;
	
	sort(intervals.begin(), intervals.end(),
		[](const vector<int>& lhv, const vector<int>& rhv) 
		 {
			 if (lhv[0] != rhv[0]) return lhv[0] < rhv[0];
			 else return lhv[1] < rhv[1];
		 });
	int count = 0; int minEnd = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i][0] < minEnd)
		{
			count++;
			minEnd = min(minEnd, intervals[i][1]);   // important
		}
		else
			minEnd = intervals[i][1];
	}
	return count;
}

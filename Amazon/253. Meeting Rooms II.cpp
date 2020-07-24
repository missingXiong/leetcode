

252. Meeting Room
bool canAttendMeetings(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end(), 
		 [](const vector<int>& lhs, const vector<int>& rhs) 
		 { return lhs[0] < rhs[0]; });
	for(int i = 1; i < intervals.size(); i++)
	{
		if(intervals[i - 1][1] > intervals[i][0])
			return false;
	}
	return true;
}

253. Meeting Rooms II
// solution 1: O(nlogn)
int minMeetingRooms(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end(), 
		[](const vector<int>& lhs, const vector<int>& rhs) 
		{ return lhs[0] < rhs[0]; });
	
	int minRoom = 0;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(const vector<int>& meeting : intervals)
	{
		while(!minHeap.empty() && minHeap.top() <= meeting[0])
			minHeap.pop();
		minHeap.push(meeting[1]);
		minRoom = std::max(minRoom, minHeap.size());
	}
	return minRoom;
}

// solution 2: O(nlogn)
int minMeetingRooms(vector<vector<int>>& intervals)
{
	map<int, int> m;   // map默认是从小到大排序，没有重复元素, build: O(nlogn)
	for(const vector<int>& meeting : intervals)
	{
		m[meeting[0]]++;
		m[meeting[1]]--;
	}
	
	int min_rooms = 0, cnt = 0;
	for(auto& p : m)
	{
		cnt += p.second;
		min_room = max(min_room, cnt);
	}
	return min_room;
}

int minMeetingRooms(vector<Interval>& intervals) 
{
    vector<pair<int, int>> changes;
    for (auto i : intervals) 
	{
        changes.push_back({i.start, 1});
        changes.push_back({i.end, -1});
    };
    sort(begin(changes), end(changes));    // O(nlogn)
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        maxrooms = max(maxrooms, rooms += change.second);
    return maxrooms;
}


218. The Skyline Problem
/*
*/
vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
	vector<vector<int>> skyline;
	vector<vector<int>> time;  // startpoint / endpoint + height
	for(const vector<int>& building : buildings)
	{
		// ******* important ****** //
		time.push_back({building[0], -building[2]});  
		time.push_back({building[1], building[2]});
	}
	
	sort(time.begin(), time.end(), 
		 [](const vector<int>& lhs, const vector<int>& rhs)
		 {return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];});
	
	int curr = 0, pre = 0;
	multiset<int, greater<int>> ms;
	ms.insert(0);
	for(const vector<int>& point : time)
	{
		if(point[1] < 0)
			ms.insert(-point[1]);
		else
			ms.erase(ms.equal_range(point[1]).first);
		
		curr = *ms.begin();
		if(curr != pre)
		{
			skyline.push_back({point[0], curr});
			pre = curr;
		}
	}
	return skyline;
}








































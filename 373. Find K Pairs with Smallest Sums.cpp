

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	    vector<vector<int>> res;
        // corner case
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0)
            return res;
        
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) 
                    { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		
		// push the root node to pq
		for(int i = 0; i < nums1.size(); i++)
			pq.emplace(i, 0);
		
		while(!pq.empty() && k-- > 0)
		{
			auto p = pq.top(); pq.pop();
			res.push_back({nums1[p.first], nums2[p.second]});
			
			if(p.second + 1 < nums2.size())
				pq.emplace(p.first, p.second + 1);
		}
		
		return res;
}

bool canCross(vector<int>& stones)
{
	unordered_set<int> dict(stones.begin(), stones.end());
	unordered_map<int, unordered_set<int>> jump = {{stones[0], {0}}};
	for (int num : stones)
	{
		for (int i : jump[num])
		{
			for (int  k = -1; k <= 1; k++)
			{
				if (i + k <= 0) continue;
				if (dict.count(num + i + k))
					jump[num + i + k].insert(i + k);
			}
		}
	}
	return !jump[stones.back()].empty();
}
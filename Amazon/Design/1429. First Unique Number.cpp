

class FirstUnique 
{
public:
	FirstUnique(vector<int>& nums) 
	{
		for(int num : nums)
			add(num);
	}

	int showFirstUnique() 
	{
		return list.empty() ? -1 : *list.begin();
	}

	void add(int value) 
	{
		q.push(value);
		if(pos.find(value) == pos.end())
		{
			list.push_back(value);
			pos[value] = list.rbegin();
		}
		else
		{
			auto it = pos[value];
			if(it != list.end()) 
			{
				list.erase(it);
				pos[value] = list.end();
			}
		}
	}
private:
	queue<int> q;
	list<int> list;
	unordered_map<int, list<int>::iterator> pos;
};

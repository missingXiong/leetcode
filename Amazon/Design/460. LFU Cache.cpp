
class LFUCache 
{
public:
	LFUCache(int capacity) 
	{
		this->capacity_ = capacity;
		minFrequency_ = 0;
		size_ = 0;
	}

	int get(int key) 
	{
		if(m_.count(key))
		{
			// delete the key node from list
			int curr_f = m_[key].second;
			f_list_[curr_f].erase(cache_[key]);
			
			// update min frequency
			if(f_list_[minFrequency_].empty())
				minFrequency_++;
			
			// update key node
			m_[key].second++;
			f_list_[m_[key].second].push_front(key);
			cache_[key] = f_list_[m_[key].second].begin();
			return m_[key].first;
		}
		else
			return -1;
	}

	void put(int key, int value) 
	{
		if(capacity_ <= 0) return;   // base condition
		
		// if key is already exist
		if(get(key) != -1)
		{
			m_[key] = {value, m_[key].second};
			return;
		}
		
		// every time put a new key, minFrequency will become 1
		f_list_[1].push_front(key);
		cache_[key] = f_list_[1].begin();
		m_[key] = {value, 1};
		
		// delete a key
		if(++size_ > capacity_)
		{
			int del = f_list_[minFrequency_].back();
			m_.erase(del);
			cache_.erase(del);
			f_list_[minFrequency_].pop_back();
			size_--;
		}
		
		minFrequency_ = 1;
	}
private:
	int capacity_;
	int minFrequency_;    
	int size_;    // current keys
	unordered_map<int, list<int>> f_list_;   // frequency => list
	unordered_map<int, pair<int, int>> m_;   // key = > <value, frequency>
	unordered_map<int, list<int>::iterator> cache_;   // key => position in list
};
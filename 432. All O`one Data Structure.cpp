struct Node
{
	int value;
	unordered_set<string> keys;
	Node(int val, unordered_set<string> k)
		: value(val), keys(k) {}
};


class AllOne 
{
public:
    /** Initialize your data structure here. */
    AllOne() 
	{
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) 
	{
		if (key_pos.find(key) == key_pos.end())
		{
			list_.push_front({0, {key}});
			key_pos[key] = list_.begin();
		}
		
		auto p = key_pos[key];
		auto nxt = next(p);
		p->keys.erase(key);

		if (nxt == list_.end() || nxt->value - p->value > 1)  // if need create a node
		{
			nxt = list_.insert(nxt, {p->value + 1, {}});
		}
		key_pos[key] = nxt;
		nxt->keys.insert(key);
		if (p->keys.empty()) list_.erase(p);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) 
	{
		if (key_pos.find(key) == key_pos.end()) return;
		
		auto p = key_pos[key];
		auto pre = prev(p);
		p->keys.erase(key);
        key_pos.erase(key);   // erase
        if (p->value - 1 > 0)
        {
            if (p == list_.begin() || p->value - pre->value > 1)  // if need create a new node
                pre = list_.insert(p, {p->value - 1, {key}});
            key_pos[key] = pre;
            pre->keys.insert(key);
        }

		if (p->keys.empty()) list_.erase(p);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() 
	{
        if (list_.empty()) return "";
		return *(((list_.rbegin())->keys).begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() 
	{
        if (list_.empty()) return "";
		return *(((list_.begin())->keys).begin());
    }
private:
	list<Node> list_;
	unordered_map<string, list<Node>::iterator> key_pos;
};


class LRUCache 
{
public:
    LRUCache(int capacity) 
    {
        capacity_ = capacity;
    }
    
    int get(int key) 
    {
        if(m_.count(key))
        {
            cache_.splice(cache_.begin(), cache_, m_[key]);
            return m_[key]->second;
        }
        else return -1;
    }
    
    void put(int key, int value) 
    {
        if(m_.count(key))
        {
            cache_.splice(cache_.begin(), cache_, m_[key]);
            m_[key]->second = value;
            return;
        }
        
        if(capacity_ == m_.size())
        {
            m_.erase(cache_.back().first);
            cache_.pop_back();
        }
        
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    list<pair<int, int>> cache_;
    int capacity_;
};


























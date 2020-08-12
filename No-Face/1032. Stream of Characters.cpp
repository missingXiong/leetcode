class Node
{
public:
	bool isWord;
	vector<Node*> children;
	Node() : isWord(false), children(26, nullptr) {}
	~Node() 
	{
		for(Node* node : children)
			delete node;
	}
};

class Trie
{
public:
	Trie() {_root = new Node();}
	~Trie() {delete _root;}
	
	void insert(string word)
	{
		Node* p = _root;
		for(char c : word)
		{
			if(p->children[c - 'a'] == nullptr)
				p->children[c - 'a'] = new Node();
			p = p->children[c - 'a'];
		}
		
		p->isWord = true;
	}
	
	bool query(char letter)
	{
		bool check = false;
		vector<Node*> newPath;
		Node* p = _root;
		_startPoints.push_back(p);
		for(Node* node : _startPoints)
		{
			if(node->children[letter - 'a'] != nullptr)
			{
				node = node->children[letter - 'a'];
				if(node->isWord) check = true;
				newPath.push_back(node);
			}
		}
		
		_startPoints = newPath;
		return check;
	}
	
	bool query(string word)
	{
		Node* p = _root;
		for(char c : word)
		{
			if(p->children[c - 'a'] != nullptr)
			{
				if(p->children[c - 'a']->isWord) return true;
				p = p->children[c - 'a'];
			}
			else
				return false;
		}
		
		return false;
	}
	
private:
	Node* _root;
	vector<Node*> _startPoints;   // search letter from startPoints
};

class StreamChecker 
{
public:
    StreamChecker(vector<string>& words) 
	{
		_tree = new Trie();
		_search = "";
		_maxlen = 0;
		
		for(string s : words)
		{
			// why insert strings in reverse order: reduce the time a lot
			_maxlen = max(_maxlen, s.length());
			std::reverse(s.begin(), s.end());
			_tree->insert(s);
		}
    }
    
    bool query(char letter) 
	{
        _search = letter + _search;
		
		if(_search.size() > _maxlen)     // pruning: very important!!!!!!!!!!!!!!!
			_search.pop_back();
		
		return _tree->query(_search);
    }

private:
	string _search;
	int _maxlen;
	Trie* _tree;
};



// this method will cost a lot of space and a lot duplicate checks
class StreamChecker1 
{
public:
    StreamChecker1(vector<string>& words) 
	{
		_tree = new Trie();
		
		for(string s : words)
			_tree->insert(s);
    }
    
    bool query(char letter) 
	{
        return _tree->query(letter);
    }

private:
	Trie* _tree;
};























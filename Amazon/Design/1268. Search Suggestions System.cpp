

class Node
{
public:
	vector<string> words;
	vector<Node*> children;
	Node() : children(26, nullptr) {}
	~Node()
	{
		for(auto p : children)
			if(p != nullptr) delete p;
	}
};

class Trie
{
public:
	Trie() {root_ = new Node();}
	~Trie() {delete root_;}
	
	void insert(const string& word)
	{
		Node* p = root_;
		for(const char& c : word)
		{
			if(p->children[c - 'a'] == nullptr)
			{
				p->children[c - 'a'] = new Node();
				p->children[c - 'a']->words.push_back(word);
			}
			else
			{
				if(p->children[c - 'a']->words.size() < 3)
					p->children[c - 'a']->words.push_back(word);
			}
			p = p->children[c - 'a'];
		}
	}
	
	vector<string> query(const string& word)
	{
		Node* p = findPrefix(word);
		return p ? p->words : vector<string>{};
	}
	
private:
	Node* root_;
	Node* findPrefix(const string& prefix)
	{
		Node* p = root_;
		for(const char& c : prefix)
		{
			if(p->children[c - 'a'])
				p = p->children[c - 'a'];
			else
				return nullptr;
		}
		return p;
	}
};

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
	sort(products.begin(), products.end());
	vector<vector<string>> ans;
	Trie* tree = new Trie();
	for(const string& s : products)
		tree->insert(s);
	
	string curr;
	for(const char& c : searchWord)
	{
		curr += c;
		vector<string> ss = tree->query(curr);
		ans.push_back(ss);
	}
	return ans;
}




















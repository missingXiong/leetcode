class Node
{
public:
	bool isword;
	vector<Node*> children;
	Node() : isword(false), children(26, nullptr) {}
	~Node()
	{
		for (Node* node: children) delete node;
	}
};

class Trie
{
public:
	Trie() { _root = new Node(); }
	~Trie() { delete _root; }
	
	void insert(string& word)
	{
		Node* p = _root;
		for (char c : word)
		{
			if (p->children[c - 'a'] == nullptr)
				p->children[c - 'a'] = new Node();
			p = p->children[c - 'a'];
		}
		p->isword = true;
	}
	
	bool search(string& word)
	{
		Node* p = _root;
		for (char c : word)
		{
			if (p->children[c - 'a'] == nullptr)
				return false;
			p = p->children[c - 'a'];
		}
		
		return p->isword;
	}

private:
	Node* _root;
};


class MagicDictionary 
{
public:
    /** Initialize your data structure here. */
    MagicDictionary() 
	{
        tree = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) 
	{
        for (string& word : dict)
			tree->insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) 
	{
        for (int i = 0; i < word.length(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				char c = j + 'a';
				char original = word[i];
				if (original == c) continue;
				word[i] = c;
				if (tree->search(word)) return true;
				word[i] = original;
			}
		}
		return false;
    }
private:
	Trie* tree;
};































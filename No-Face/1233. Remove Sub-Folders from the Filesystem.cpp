
class Node
{
public:
	bool isFolder;
	unordered_map<string, Node*> children;
	Node() : isFolder(false) {}
};

class Trie 
{
public:
	Trie() { _root = new Node(); }
	~Trie() { delete _root; }
	
	bool insert(const vector<string>& strs)
	{
		Node* p = _root;
		for(string f : strs)
		{
			if(p->children.find(f) == p->children.end())
			{
				p->children[f] = new Node();
			}
			else
			{
				Node* temp = p->children[f];
				if(temp->isFolder) return true;
			}
			
			p = p->children[f];
		}
		p->isFolder = true;
		return false;
	}
	
private:
	Node* _root;
};


vector<string> removeSubfolders(vector<string>& folder)
{
	std::sort(folder.begin(), folder.end());
	vector<string> ans;
	
	Trie* tree = new Trie();
	for(string f : folder)
	{
		vector<string> docs;
		string s = "";
		for(int i = 0; i < f.length(); i++)
		{
			if(f[i] == '/')
			{
				if(!s.empty()) docs.push_back(s);
				s = "";
			}
			else
				s += f[i];
		}
		
		if(!s.empty()) docs.push_back(s);
		
		if(!tree->insert(docs))
			ans.push_back(f);
	}
	return ans;
}


vector<string> removeSubfolders(vector<string>& folder)
{
	std::sort(folder.begin(), folder.end());
	vector<string> ans;
	ans.push_back(folder[0]);
	
	for(int i = 1; i < folder.size(); i++)
	{
		string cmp = ans[ans.size() - 1] + "/";
		if(folder[i].substr(0, cmp.length()) != cmp)
			ans.push_back(folder[i]);
	}
	return ans;
}










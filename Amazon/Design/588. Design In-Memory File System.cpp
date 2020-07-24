

struct TrieNode
{
	bool isFile;
	string content;
	unordered_map<string, TrieNode*> children;
	
	TrieNode() : isFile(false) {}
};

class FileSystem 
{
public:
	FileSystem() 
	{
		root_ = new TrieNode();
	}

	vector<string> ls(string path) 
	{
		TrieNode* p = root_;
		vector<string> dirs = breakPath(path);
		
		if(!dirs.empty())
		{
			for(const string& s : dirs)
				p = p->children[s];
		}
		
		if(p->isFile) return {dirs.back()};
        vector<string> ans;
		for(auto pair : p->children) ans.push_back(pair.first);
		sort(ans.begin(), ans.end());
        return ans;
	}

	void mkdir(string path) 
	{
		TrieNode* p = root_;
		vector<string> dirs = breakPath(path);
		for(const string& s : dirs)
		{
			if(!p->children.count(s))
			{
				TrieNode* node = new TrieNode();
				p->children[s] = node;
			}
			p = p->children[s];
		}
	}

	void addContentToFile(string filePath, string content) 
	{
		TrieNode* p = root_;
		vector<string> dirs = breakPath(filePath);
		for(const string& s : dirs)
		{
			if(!p->children.count(s))
				p->children[s] = new TrieNode();
			p = p->children[s];
		}
		p->isFile = true;
		p->content += content;
	}

	string readContentFromFile(string filePath) 
	{
		TrieNode* p = root_;
		vector<string> dirs = breakPath(filePath);
		for(const string& s : dirs)
			p = p->children[s];
		return p->content;
	}
private:
	TrieNode* root_;
	
	vector<string> breakPath(const string& path)
	{
		vector<string> dirs;
		string subPath;
		for(const char c : path)
		{
			if(c == '/')
			{
				if(!subPath.empty())
				{
					dirs.push_back(subPath);
					subPath = "";
				}
			}
			else subPath += c;
		}
		if(!subPath.empty()) dirs.push_back(subPath);
		return dirs;
	}
};

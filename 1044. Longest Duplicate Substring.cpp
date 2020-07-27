

// DP : longest common substring
string longestDupSubstring(string S)
{
    int n = S.length();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	int ans = 0, end = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
            if(i == j) continue;  // very important
            
			if(S[i - 1] == S[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if(ans < dp[i][j])
                {
                    ans = dp[i][j];
                    end = i - 1;
                }
			}
			else
				dp[i][j] = 0;
		}
	}

	return ans == 0 ? "" : S.substr(end + 1 - ans, ans);
}

// Trie Tree + binary Search: O(logn * (n * len))
class Node
{
	vector<Node*> children;
	Node(): children(26, nullptr) {}
	~Node()
	{
		for(Node* node : children)
			delete node;
	}
};

class Trie
{
public:
	Trie() { _root = new Node(); }
	~Trie() { delete _root; }
	
	bool insert(string s)
	{
		Node* p = _root;
		bool isRepeat = true;
		for(char c : s)
		{
			if(p->children[c - 'a'] == nullptr)
			{
				isRepeat = false;
				p->children[c - 'a'] = new Node();
			}
			
			p = p->children[c - 'a'];
		}
		
		return isRepeat;
	}

private:
	Node* _root;
};

string search(string S, int len)
{
	Trie* tree = new Trie();
	string s = "";
	for(int i = 0; i <= S.length() - len; i++)
	{
		string subs = S.substr(i, len);
		if(tree->insert(subs))
			s = subs;
	}
	
	delete tree;
	return s;
}

string longestDupSubstring(string S)
{
	int low = 1, high = S.length();
	
	string ans = "";
	while(low <= high)
	{
		int len = low + (high - low) / 2;
		string s = search(S, len);
		if(!s.empty())
		{
			low = len + 1;
			ans = s;
		}
		else
			high = len - 1;
	}
	
	return ans;
}

// suffix array + LCP array
string longestDupSubstring(string S)
{
	vector<pair<int, string>> suffixes;
	vector<int> lcp(S.length(), 0);
	
	buildSA(S, suffixes);
	buildLCP(suffixes, lcp);
	
	int maxlen = 0;
	string ans = "";
	for(int i = 0; i < lcp.size(); i++)
	{
		if(maxlen < lcp[i])
		{
			maxlen = lcp[i];
			ans = suffixes[i].second;
		}
	}
	
	return ans;
}

void buildSA(string S, vector<pair<int, string>>& suffixes)
{
	for(int i = 0; i < S.length(); i++)
		suffixes.emplace_back(i, S.substr(i));
	sort(suffixes.begin(), suffixes.end(), 
		[](pair<int, string> a, pair<int, string> b) {return a.second < b.second;});
}

void buildLCP(vector<pair<int, string>>& suffixes, vector<int>& lcp)
{
	for(int i = 0; i < lcp.size() - 1; i++)
	{
		string s1 = suffixes[i].second;
		string s2 = suffixes[i + 1].second;
		int len = min(s1.length(), s2.length());
		int j = 0;
		while(j < len && s1[j] == s2[j]) j++;
		
		lcp[i] = j;
	}
}



























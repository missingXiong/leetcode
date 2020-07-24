

79. Word Search
bool exist(vector<vector<char>>& board, string word)
{
	if(board.size() == 0) return false;
	int m = board.size();
	int n = board[0].size();
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(DFS(board, word, 0, i, j, m, n)) return true;
		}
	}
	return false;
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
bool DFS(vector<vector<char>>& board, string word, int start, int x, int y, int m, int n)
{
	if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '*' || board[x][y] != word[start]) return false;
	if(start == word.length() - 1) return true;

	// choose => explore => unchoose
	char c = board[x][y];
	board[x][y] = '*';     // choose
	for(int i = 0; i < 4; i++)   // explore
	{
		if(DFS(board, word, start + 1, x + dx[i], y + dy[i], m, n))
			return true;
	}
	board[x][y] = c;    // unchoose
	return false;
}

212. Word Search II
/*
solution 1: 有多少个单词就要DFS遍历board几次
solution 2: 只需要遍历一次board
*/
// TLE
vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	if(board.size() == 0) return false;
	int m = board.size();
	int n = board[0].size();
	unordered_set<string> ans;
	for(string& word : words)
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(DFS(board, word, 0, i, j, m, n))
					ans.insert(word);
			}
		}
	}
	
	return vector<string>(ans.begin(), ans.end());
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
bool DFS(vector<vector<char>>& board, string word, int start, int x, int y, int m, int n)
{
	if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '*' || board[x][y] != word[start]) return false;
	if(start == word.length() - 1) return true;

	int result = false;
	char c = board[x][y];
	board[x][y] = '*';
	for(int i = 0; i < 4; i++)
	{
		if(DFS(board, word, start + 1, x + dx[i], y + dy[i], m, n))
		{
			result = true;
			break;
		}
	}
	board[x][y] = c;
	return result;
}

// Trie Tree + DFS
class TrieNode
{
public:
	bool is_word;
	string word;
	vector<TrieNode*> children;
	
	TrieNode() : is_word(false), word(""), children(26, nullptr) {}
};

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	vector<string> ans;
	if(board.size() == 0) return ans;
	
	int m = board.size();
	int n = board[0].size();
	TrieNode root;
	for(const string& word : words)
	{
		TrieNode* p = &root;
		for(const char c : word)
		{
			if(p->children[c - 'a'] == nullptr)
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->is_word = true;
		p->word = word;
	}
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			search(board, m, n, i, j, &root, ans);
	return ans;
}

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
void search(vector<vector<char>>& board, int m, int n, 
			int x, int y, TrieNode* root, vector<string>& ans)
{
	if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '#')
		return;

	char c = board[x][y];
	root = root->children[c - 'a'];
	if(root == nullptr) return;
	if(root->is_word)
	{
		ans.push_back(root->word);
		root->is_word = false;
	}
	
	board[x][y] = '#';
	for(int i = 0; i < 4; i++)
		search(board, m, n, x + dx[i], y + dy[i], root, ans);
	board[x][y] = c;
}




























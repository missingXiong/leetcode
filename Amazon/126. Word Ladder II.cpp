

127. Word Ladder
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	if(wordList.size() == 0) return 0;
	unordered_map<string, bool> visited;
	for(const string& s : wordList) visited[s] = false;  // unordered_set and erase() also can be used
	if(!visited.count(endWord)) return 0;
	
	if(visited.count(beginWord)) visited[beginWord] = true;
	queue<string> q;
	q.push(beginWord);
	int ans = 1;
	while(!q.empty())
	{
		int size = q.size();
		ans++;
		while(size--)
		{
			string word = q.front(); q.pop();
			for(int i = 0; i < word.size(); i++)
			{
				string copy = word;
				for(int j = 0; j < 26; j++)
				{
					copy[i] = j + 'a';
					if(copy == endWord) return ans;
					if(visited.count(copy) && !visited[copy])
					{
						visited[copy] = true;
						q.push(copy);
					}
				}
			}
		}
	}
	return 0;
}

// two-end BFS
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> dict(wordList.begin(), wordList.end());
	if(dict.find(endWord) == dict.end()) return 0;

	unordered_set<string> fromSrc;
	unordered_set<string> fromDest;
	fromSrc.insert(beginWord);
	fromDest.insert(endWord);
	
	dict.erase(beginWord);
	dict.erase(endWord);
	
	int ans = 0;
	while(!fromSrc.empty() && !fromDest.empty())
	{
		ans++;
		if(fromSrc.size() > fromDest.size())    // balance
			swap(fromSrc, fromDest);
		unordered_set<string>::iterator it = fromSrc.begin();
		unordered_set<string> temp;
		for(; it != fromSrc.end(); it++)
		{
			string word = *it;
			for(int i = 0; i < word.length(); i++)
			{
				char letter = word[i];
				for(char j = 'a'; j <= 'z'; j++)
				{
					word[i] = j;
					if(fromDest.count(word))
						return ans + 1;
					if(dict.count(word))
					{
						temp.insert(word);
						dict.erase(word);
					}
				}
				word[i] = letter;
			}
		}
		swap(temp, fromSrc);
	}
	return 0;
}

vector<string> neighbors(string& word, unordered_set<string>& dict)
{
	vector<string> nbs;
	for(int i = 0; i < word.length(); i++)
	{
		char c = word[i];
		for(int j = 'a'; j <= 'z'; j++)
		{
			word[i] = j;
			if(dict.count(word)) nbs.push_back(word);
		}
		word[i] = c;
	}
	return nbs;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	vector<vector<string>> ans;
	unordered_set<string> dict(wordList.ebgin(), wordList.end());
	if(!dict.count(endWord)) return ans;
	
	bool isFind = false;
	queue<vector<string>> q;
	q.push({beginWord});
	if(dict.count(beginWord)) dict.erase(beginWord);
	
	while(!q.empty())
	{
		int size = q.size();
		unordered_set<string> visited;   // for every level
		while(size--)
		{
			vector<string> ss = q.front(); q.pop();
			vector<string> nbs = neighbors(ss.back(), dict);
			for(string& s : nbs)
			{
				vector<string> add(ss.begin(), ss.end());
				add.push_back(s);
				if(s == endWord) 
				{
					isFind = true;
					ans.push_back(add);
				}
				visited.insert(s);
				q.push(add);
			}
		}
		if(isFind) break;
		for(const string& s : visited) 
			dict.erase(s);
	}
	return ans;
}























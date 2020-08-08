vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
{
	if (words.size() == 0) return {};
	unordered_set<string> dict(words.begin(), words.end());
	unordered_map<string, bool> map;
	vector<string> ans;
	for (string& word : words)
	{
		if (search(map, dict, word)) ans.push_back(word);
	}
	return ans;
}

bool search(unordered_map<string, bool>& map, unordered_set<string>& dict, string& word)
{
    // if (word.length() == 0) return false;
	if (map.count(word)) return map[word];
	
	for (int i = 1; i < word.length(); i++)   // length
	{
        string left = word.substr(0, i);
		string right = word.substr(i);
		if (dict.count(left) && (dict.count(right) || search(map, dict, right)))
		{
			return map[word] = true;	
		}
	}
	return map[word] = false;
}


// https://leetcode.com/problems/concatenated-words/discuss/348972/Java-Common-template-Word-Break-I-Word-Break-II-Concatenated-Words
// practice: 139. word break && 140. word break 2
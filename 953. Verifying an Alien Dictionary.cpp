bool isAlienSorted(vector<string>& words, string order)
{
	if(words.size() == 1) return true;
	unordered_map<char, int> map;
	for(int i = 0; i < order.size(); i++)
		map[order[i]] = i;
	
	for(int i = 0; i < words.size() - 1; i++)
	{
		int j = i + 1;
		// compare ith and jth words
		if(!compare(words[i], words[j], map))
			return false;
	}
	
	return true;
}

bool compare(string word1, string word2, unordered_map<char, int>& map)
{
	for(int i = 0, j = 0; i < word1.size() && j < word2.size(); i++, j++)
	{
		if(map[word1[i]] > map[word2[j]])
			return false;
		else if(map[word1[i]] < map[word2[j]])
			return true;
	}
	
	return word1.length() < word2.length();
}
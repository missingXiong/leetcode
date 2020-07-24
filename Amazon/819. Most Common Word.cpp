


string mostCommonWord(string paragraph, vector<string>& banned)
{
	if(paragraph.length() == 0) return "";
	
	for(char& c : paragraph)
		c = isalpha(c) ? tolower(c) : ' ';
	unordered_map<string ,int> counts;
	istringstream iss(paragraph);
	string word;
	while(iss >> word)
		counts[word]++;

	for(string& s : banned) counts[s] = -1;
	
	string ans;
	int maxCount = 0;
	for(auto& p : counts)
	{
		if(p.second > maxCount)
		{
			ans = p.first;
			maxCount = p.second;
		}
	}
	return ans;
}
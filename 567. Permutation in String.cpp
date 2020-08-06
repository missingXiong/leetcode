

// fixed slide window
bool checkInclusion(string s1, string s2)
{
	if (s1.length() > s2.length()) return false;
	
	int l1 = s1.length();
	int l2 = s2.length();
	vector<int> cnt(26, 0);
	for (char c : s1) cnt[c - 'a']++;
	
	vector<int> temp(26, 0);
	for (int i = 0; i < l2; i++)
	{
		if (i >= l1)
			--temp[s2[i - l1] - 'a'];
		++temp[s2[i] - 'a'];
		
		if (temp == cnt) return true;
	}
	return false;
}

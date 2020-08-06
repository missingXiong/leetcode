
int lengthOfLongestSubstring(string s)
{
	int len = s.length();
	if (len == 0) return 0;
	int ans = 0;
	unordered_map<char, int> cnt;
	for (int left = 0, right = 0; right < len; right++)
	{
		++cnt[s[right]];
		while (cnt[s[right]] > 1)
		{
			--cnt[s[left++]];
		}
		
		ans = max(ans, right - left + 1);
	}
	
	return ans;
}
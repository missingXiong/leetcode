

int lengthOfLongestSubstring(string s)
{
	if(s.length() == 0) return 0;
	
	unordered_set<char> contain;
	int j = 0;
	int maxlen = 0;
	for(int i = 0; i < s.length(); i++)
	{
		while(j < s.length() && contain.count(s[i]))
			contain.erase(s[j++]);
		
		if(!contain.count(s[i]))
		{
			contain.insert(s[i]);
			maxlen = max(maxlen, i - j + 1);
		}
	}
	return maxlen;
}

int lengthOfLongestSubstring(string s)
{
	if(s.length() == 0) return 0;
	unordered_map<char, int> map;
	int maxlen = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(map.count(s[i]))
			start = max(start, map[s[i]]);
		map[s[i]] = i;
        maxlen = max(maxlen, i - start);
	}
	return maxlen;
}

209. Minimum Size Subarray Sum
int minSubArrayLen(int s, vector<int>& nums)
{
	if(nums.size() == 0) return 0;
	
	int curr_sum = 0;
	int j = 0;
	int minlen = INT_MAX;
	for(int i = 0; i < nums.size(); i++)
	{
		curr_sum += nums[i];
		while(j < nums.size() && curr_sum >= s)
		{
			minlen = min(minlen, i - j + 1);
			curr_sum -= nums[j++];
		}
	}
	return minlen == INT_MAX ? 0 : minlen;
}

76. Minimum Window Substring
bool isValid(unordered_map<char, int>& window, unordered_map<char, int>& dict)
{
	if(window.size() != dict.size()) return false;
	for(auto& p : dict)
	{
		if(window[p.first] < p.second)
			return false;
	}
	return true;
}

string minWindow(string s, string t)
{
	if(s.length() < t.length()) return "";
	
	int left = 0;
	int start = 0, end = s.length();
	string ans;
	unordered_map<char, int> window;
	unordered_map<char, int> dict;
	for(const char c : t) dict[c]++;
	for(int right = 0; right < s.length(); right++)
	{
		if(dict.find(s[right]) != dict.end())
			dict
		
		while(left < s.length() && isValid(window, dict))
		{
			if(right - left + 1 < end - start + 1)
				{start = left; end = right;}
			if(window.find(s[left]) != window.end())
			{
				if(--window[s[left]] == 0)
					window.erase(s[left]);
			}
			left++;
		}
	}
	
	return end - start + 1 > s.length() ? "" : s.substr(start, end - start + 1);
}

// optimize
string minWindow(string s, string t)
{
	if(s.length() < t.length()) return "";
	
	int left = 0;
	int start = 0, len = INT_MAX;
	string ans;
	int count = t.length();
	unordered_map<char, int> dict;
	for(const char c : t) dict[c]++;
	for(int right = 0; right < s.length(); right++)
	{
		if(dict.find(s[right]) != dict.end())
			if(--dict[s[right]] >= 0) count--;
		
		while(left < s.length() && count == 0)
		{
			if(right - left + 1 < len)
				{start = left; len = right - left + 1;}
			if(dict.find(s[left]) != dict.end())
				if(++dict[s[left]] > 0) count++;
			left++;
		}
	}
	
	return len == INT_MAX ? "" : s.substr(start, len);
}


















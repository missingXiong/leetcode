
// 计算所有的回文串
vector<vector<bool>> calcPalin(string s)
{
	int len = s.length();
	vector<vector<bool>> palin(len, vector<bool>(len, false));
	// odd length
	for(int center = 0; center < len; center++)
	{
		// extend string from center to both direction
		int i = center, j = center;
		while(i >= 0 && j < len && s[i] == s[j])
		{
			palin[i][j] = true;
			i--, j++;
		}
	}
	// even length
	for(int center = 1; center < len; center++)
	{
		int i = center - 1, j = center;
		while(i >= 0 && j < len && s[i] == s[j])
		{
			palin[i][j] = true;
			i--, j++;
		}
	}

	return palin;
}

bool isPalindrome(string s)
{
	int len = s.length();
	for(int i = 0; i < len / 2 + 1; i++)
	{
		if(s[i] != s[len - i + 1]) return false;
	}
	return true;
}

// 写法一
string longestPalindrome(string s)
{
	int maxlen = 0, lo = 0, hi = 0;
	int len = s.length();
	for(int center = 0; center < len; center++)
	{
		int paliLen = -1;
		int i = center, j = center;
		while(i >= 0 && j < len && s[i] == s[j])
		{
			paliLen += 2;
			if(paliLen > maxlen) 
			{
				lo = i;
				hi = j;
				maxlen = paliLen;
			}
			i--; j++;
		}
	}
	for(int center = 1; center < len; center++)
	{
		int paliLen = 0;
		int i = center - 1, j = center;
		while(i >= 0 && j < len && s[i] == s[j])
		{
			paliLen += 2;
			if(paliLen > maxlen) 
			{
				lo = i;
				hi = j;
				maxlen = paliLen;
			}
			i--; j++;
		}
	}
	return s.substr(lo, hi - lo + 1);
}

// 写法二
int getLen(string& s, int lo, int hi)
{
	int len = s.length();
	while(lo >= 0 && hi < len && s[lo] == s[hi])
	{
		lo--;
		hi++;
	}
	return hi - lo - 1;
}
string longestPalindrome(string s)
{
	int len = s.length();
	int maxlen = 0, start = 0;
	for(int i = 0; i < len; i++)
	{
		int curr = max(getLen(s, i, i), getLen(s, i, i + 1));
		if(maxlen < curr)
		{
			maxlen = curr;
			start = i - (maxlen - 1) / 2;
		}
	}
	return s.substr(start, maxlen);
}




































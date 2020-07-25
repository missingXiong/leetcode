680. Valid Palindrome II
bool validPalindrome(string s)
{
	for(int i = 0, j = s.length() - 1; i < j; i++, j--)
	{
		if(s[i] != s[j])
			return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
	}
	return true;
}

bool isPalindrome(string s, int m, int k)
{
	for(; m < k; m++, k--)
	{
		if(s[m] != s[k]) return false;
	}
	return true;
}

1216. Valid Palindrome III
// LTE
bool isValidPalindrome(string s, int k)
{
	return recursion(s, 0, s.length() - 1, k);
}

bool recursion(string s, int start, int end, int times)
{
	for(; start < end; start++, end--)
	{
		if(s[start] != s[end])
		{
			if(times == 0) return false;
			else
			{
				return recursion(s, start + 1, end, times - 1)
					|| recursion(s, start, end - 1, times - 1);
			}
		}
	}
	
	return true;
}

// DP
bool isValidPalindrome(string s, int k)
{
	return s.length() - longestSubsequence(s) <= k;
}

// 516 Longest Palindrome Subsequence
int longestSubsequence(string s)
{
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++)
		dp[i][i] = 1;
	
	for(int len = 2; len <= n; len++)
	{
		for(int i = 0; i <= n - len; i++)
		{
			int j = len + i - 1;
			if(s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	
	return dp[0][n - 1];
}




























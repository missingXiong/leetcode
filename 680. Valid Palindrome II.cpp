bool validPalindrome(string s)
{
	int times = 1;
	return isValid(s, 0, s.length() - 1, times);
}

bool isValid(string& s, int i, int j, int times)
{
	while (i < j)
	{
		if (s[i] == s[j])
		{
			i++; j--;
		}
		else if (times > 0)
        {
            return isValid(s, i, j - 1, times - 1) || isValid(s, i + 1, j, times - 1);
        }
        else
            return false;
	}
	
	return true;
}
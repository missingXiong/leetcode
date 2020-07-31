bool backspaceCompare(string S, string T)
{
	int cnt1 = 0, cnt2 = 0;
	int i = S.size() - 1;
	int j = T.size() - 1;
	
	while(i >= 0 || j >= 0)
	{
		while(i >= 0 && (S[i] == '#' || cnt1 > 0))
		{
			if(S[i] == '#') cnt1++;
			else cnt1--;
			i--;
		}
		
		while(j >= 0 && (T[j] == '#' || cnt2 > 0))
		{
			if(T[i] == '#') cnt2++;
			else cnt2--;
			j--;
		}
		
		if(i >= 0 && j >= 0 && (S[i] == S[j]))
		{
			i--;
			j--;
		}
		else
			return i == -1 && j == -1;
	}
	
	return true;
}
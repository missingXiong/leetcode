string addStrings(string num1, string num2)
{
	string ans;
	int len1 = num1.length() - 1, len2 = num2.length() - 1;
	int sum = 0;
	while(len1 >= 0 || len2 >= 0 || sum > 0)
	{
		if (len1 >= 0) sum += (num1[len1--] - '0');
		if (len2 >= 0) sum += (num2[len2--] - '0');
		
		stk.push_back(sum % 10 + '0');
		sum /= 10;
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}
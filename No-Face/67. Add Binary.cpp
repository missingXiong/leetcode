string addBinary(string a, string b)
{
	int len_a = a.length() - 1;
	int len_b = b.length() - 1;
	int carry = 0;
	string ans = "";
	while (len_a >= 0 || len_b >= 0 || carry)
	{
		if (len_a >= 0) carry += (a[len_a--] - '0');
		if (len_b >= 0) carry += (b[len_b--] - '0');
		ans.push_back((carry % 2) + '0');
		carry /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
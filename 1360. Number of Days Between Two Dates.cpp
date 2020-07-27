int daysBetweenDates(string date1, string date2)
{
	vector<int> v1, v2;
	split(date1, v1);
	split(date2, v2);
	
	vector<int> remain(3, 0); // (day, month, year)
	for(int i = 0; i < v1.size(); i++)
	{
		if(v1[i] < v2[i])
		{
			// 借位
			v1[i + 1] = v1[i + 1] - 1;
			if(i == 0)
		}
		else
			remain[i] = v1[i] - v2[i];
	}
	
}

int month(int n)
{
	if(n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
		return 31;
	else
		return 30;
}

void split(string date, vector<int>& v)
{
	int day = std::stoi(date.substr(8 ,2));
	int month = std::stoi(date.substr(5, 2));
	int year = std::stoi(date.substr(0, 4));
	
	v.push_back(day);
	v.push_back(month);
	v.push_back(year);
}
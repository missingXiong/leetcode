vector<int> exclusiveTime(int n, vector<string>& logs)
{
    vector<int> ans(n);
	stack<int> stk;
	int prev = 0;
	for (string& log : logs)
	{
		int first = log.find_first_of(':');
		int second = log.find_first_of(':', first + 1);
		int id = stoi(log.substr(0, first));
		int curr = stoi(log.substr(second + 1));
		string status = log.substr(first + 1, second - first - 1);

		if (status == "start")
		{
			if (!stk.empty()) ans[stk.top()] += curr - prev;
			stk.push(id);
			prev = curr;
		}
		else
		{
			ans[stk.top()] += curr - prev + 1;
			stk.pop();
			prev = curr + 1;
		}
	}
	return ans;
}
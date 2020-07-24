#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// corner case : " 3/2 "
int calculate(string s)
{
	if(s.length() == 0) return 0;
	s += '+';      
	char curr_op = '+';
	int curr_num = 0;
	stack<int> stk;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ') continue;
		if(isdigit(s[i]))
			curr_num = curr_num * 10 + s[i] - '0';
		else
		{
			switch(curr_op)
			{
				case '-' : stk.push(-curr_num); break;
				case '+' : stk.push(curr_num); break;
				case '*' : 
					{
						int num = stk.top() * curr_num; stk.pop();
						stk.push(num); break;
					}
				case '/' :
					{
						int num = stk.top() / curr_num; stk.pop();
						stk.push(num); break;
					}
			}
			
			curr_op = s[i];
			curr_num = 0;
		}
	}
	
	int res = 0;
	while(!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
	return res;
}

224. Basic Calculator
int calculate(string s)
{
	if(s.length() == 0) return 0;
	
	int pos = 0;
	return evaluate(s, pos);
}

int evaluate(string& s, int& pos)
{
	int ans = 0;
	bool flag = false;
	char curr_op = '+';
	while(pos < s.length() && s[pos] != ')')
	{
		if(s[pos++] == ' ') continue;
		if(s[pos] == '+' || s[pos] == '-')
			curr_op = s[pos++];
		else if(s[pos] == '(')
		{
			pos++;
			int sub = evaluate(s, pos);
			ans = curr_op == '+' ? ans + sub : ans - sub;
		}
		else
		{
			int num = 0;
			while(pos < s.length() && isdigit(s[pos]))
				num = num * 10 + (s[pos++] - '0');
			ans = curr_op == '+' ? ans + num : ans - num;
		}
	}
	pos++;
	return ans;
}






































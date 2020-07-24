

class MinStack 
{
public:
	/** initialize your data structure here. */
	MinStack() 
	{
		
	}

	void push(int x) 
	{
		stk.push(x);
		if(minStk.empty() || x <= minStk.top())
			minStk.push(x);
	}

	void pop() 
	{
		int x = stk.top(); stk.pop();
		if(minStk.top() == x) minStk.pop();
	}

	int top() 
	{
		return stk.top();
	}

	int getMin() 
	{
		return minStk.top();
	}
private:
	stack<int> stk;
	stack<int> minStk;
};

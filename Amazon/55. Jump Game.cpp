
55. Jump Game
// time complexity: (n^2)
// dp[i] : 能否到达i
bool canJump(vector<int>& nums)
{
	int n = nums.size();
	if(n == 0) return false;
	vector<bool> dp(n, false);
	dp[0] = true;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(nums[j] >= i - j)
				if(dp[i] = dp[j]) break;
		}
	}
	return dp[n - 1];
}

// dp[i] : 从i出发最远能跳到哪里
bool canJump(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(n, -1);
	dp[0] = nums[0];
	for(int i = 1; i < n; i++)
	{
		if(dp[i - 1] >= i)
			dp[i] = max(dp[i - 1], nums[i] + i);
	}
	return dp[n - 1] == -1 ? false : true;
}

// optimize space complexity
bool canJump(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(2, -1);
	dp[0] = nums[0];
	int old = 0, now = 0;
	for(int i = 1; i < n; i++)
	{
		old = now;
		now = 1 - now;
		dp[now] = -1;
		if(dp[old] >= i)
			dp[now] = max(dp[old], nums[i] + i);
	}
	return dp[now] == -1 ? false : true;
}

45. Jump Game II
// TLE
int jump(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(nums[j] >= i - j && dp[j] != INT_MAX)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	return dp[n - 1];
}

// BFS
/*
[2, 3, 1, 1, 4]
=> level 1: 2
level 2: 3 1
level 3: 1 4
*/
// time comlexity: O(n)  space comlexity: O(1)
int jump(vector<int>& nums)
{
	int n = nums.size();
	int i = 0, end = 0, maxend = 0, step = 0;
	while(end < n - 1)
	{
		step++;
		for(; i <= end; i++)
		{
			maxend = max(maxend, i + nums[i]);
			if(maxend >= n - 1) return step;
		}
		if(end == maxend) break;
		end = maxend;
	}
	return n == 1 ? 0 : -1;
}

int jump(vector<int>& nums)
{
	int n = nums.size();
	int end = 0;    // 当前最远跳多远
	int maxend = 0;   // 下一步最远跳多远
	int step = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == n - 1) return step;
		maxend = max(maxend, i + nums[i]);
		if(i == end)   // 到达当前能跳的最远的地方，开始下一次跳跃
		{
			step++;
			end = maxend;
			
			if(end >= n - 1) break;
		}
	}
	return step;
}






















871. Minimum Number of Refueling Stops

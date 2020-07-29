// O((n - K) * K)
int minKBitFlips(vector<int>& A, int K)
{
	int size = A.size();
	int times = 0;
	for(int i = 0; i <= size - K; i++)
	{
		if(A[i] == 0) // need flip
		{
			times++;
			for(int j = i; j < i + K; j++) // will cause duplicate flips
				A[j] = 1 - A[j];
		}
	}
	
	// check the last window
	for(int i = size - K; i < size; i++)
		if(A[i] == 0) return -1;
	return times;
}

// O(n)
int minKBitFlips(vector<int>& A, int K)
{
	queue<int> q;     // size of queue indicates the number of flip
	int count = 0;
	for(int i = 0; i < A.size(); i++)
	{
		// even flips, A[i] does not change
		// odd flips, A[i] = 1 - A[i];
		A[i] = q.size() % 2 == 0 ? A[i] : 1 - A[i];

		if(A[i] == 0)
		{
			// after flip A[i] becomes 0, so A[i] needs one extra flip
			count++;
			q.push(i + K - 1);
		}

		if(!q.empty() && i == q.front()) q.pop();
	}
	
	return q.empty() ? count : -1;
}
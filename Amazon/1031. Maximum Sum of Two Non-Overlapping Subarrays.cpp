

// time complexity: O(n^2) space complexity: O(n)
typedef tuple<int, int, int> tp;
int maxSumTwoNoOverlap(vector<int>& A, int L, int M) 
{
	int size = A.size();
	vector<tp> vL;
	int sumL = 0;
	for(int i = 0; i < size; i++)
	{
		sumL += A[i];
		if(i + 1 >= L)
		{
			vL.emplace_back(sumL, i - L + 1, i);
			sumL -= A[i - L + 1];
		}
	}
	
	vector<tp> vM;
	int sumM = 0;
	for(int i = 0; i < size; i++)
	{
		sumM += A[i];
		if(i + 1 >= M)
		{
			vM.emplace_back(sumM, i - M + 1, i);
			sumM -= A[i - M + 1];
		}
	}
	
	int ans = 0;
	for(int i = 0; i < vL.size(); i++)
    {
		for(int j = 0; j < vM.size(); j++)
		{
			// check if they have overlap 
			int low = max(get<1>(vL[i]), get<1>(vM[j]));
			int high = min(get<2>(vL[i]), get<2>(vM[j]));
			if(high >= low) continue;
			
			ans = max(ans, get<0>(vL[i]) + get<0>(vM[j]));
		}
	}
	return ans;
}

// prefix
int maxSumTwoNoOverlap(vector<int>& A, int L, int M)
{
	vector<int> prefix(A.size());
	prefix[0] = A[0];
	for(int i = 1; i < A.size(); i++)
		prefix[i] = prefix[i - 1] + A[i];
	return max(maxValue(prefix, L, M), maxValue(prefix, M, L));
}

int maxValue(vector<int>& prefix, int L, int M)
{
	int ans = prefix[L + M - 1], maxL = prefix[L - 1];
	for(int i = L + M; i < prefix.size(); i++)
	{
		maxL = max(maxL, prefix[i - M] - prefix[i - M - L]);  // 不断更新最大值
		ans = max(ans, maxL + prefix[i] - prefix[i - M]);
	}
	return ans;
}






































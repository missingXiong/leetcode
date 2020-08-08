int maxHeap_size;
int minHeap_size;
vector<double> medians;
priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
unordered_map<int, int> deletes;

void pushMedians()
{
	if (maxHeap_size == minHeap_size)
		medians.push_back(((double)maxHeap.top() + (double)minHeap.top()) / 2.0);
	else if (maxHeap_size > minHeap_size)   // maxHeap.size > minHeap.size
		medians.push_back(maxHeap.top());
	else
		medians.push_back(minHeap.top());
}

vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
	const int diff = k % 2;       // difference of size between 2 heaps

	// initialize 2 heaps
	for (int i = 0; i < k; i++)
		maxHeap.push(nums[i]);
	for (int i = 0; i < k / 2; i++)
	{
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}

	maxHeap_size = maxHeap.size();
	minHeap_size = minHeap.size();
	
	pushMedians();

	/*
	1. delete nums[i - k]: record nums[i - k] and delete it later
	3. push nums[i]: balance 2 heaps
	4. check the top of 2 heaps, delete elements in hash table if can
	5. pushMedians();
	*/
	
	for (int i = k; i < nums.size(); i++)
	{
		// delete nums[i - k]: not really delete
		deletes[nums[i - k]]++;
		if (nums[i - k] <= maxHeap.top())  
			maxHeap_size--;
		else
			minHeap_size--;

		// push nums[i]
		if (nums[i] <= maxHeap.top())  // push into maxHeap
		{
			maxHeap.push(nums[i]);
			maxHeap_size++;
		}
		else
		{
			minHeap.push(nums[i]);
			minHeap_size++;
		}

		// balance 2 heaps
		if ((maxHeap_size - minHeap_size) > diff)   // maxHeap needs pop
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap_size--;
			minHeap_size++;
		}
		else if ((minHeap_size - maxHeap_size) > diff) // minHeap needs pop
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
			maxHeap_size++;
			minHeap_size--;
		}

		// check the top of 2 heaps
		while (!maxHeap.empty() && deletes.count(maxHeap.top()))
		{
			if (--deletes[maxHeap.top()] == 0) deletes.erase(maxHeap.top());
			maxHeap.pop();
		}
		while (!minHeap.empty() && deletes.count(minHeap.top()))
		{
			if (--deletes[minHeap.top()] == 0) deletes.erase(minHeap.top());
			minHeap.pop();
		}

		pushMedians();
	}

	return medians;
}

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() 
	{
        
    }
    
    void addNum(int num) 
	{
        if(maxHeap.empty() || maxHeap.top() < num) minHeap.push(num);
		else maxHeap.push(num);
		
		if(maxHeap.size() - 1 > minHeap.size())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		
		if(minHeap.size() - 1 > maxHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    
    double findMedian() 
	{
        if(maxHeap.size() == minHeap.size())
			return (minHeap.top() + maxHeap.top()) / 2;
		else if(maxHeap.size() < minHeap.size())
			return minHeap.top();
		else
			return maxHeap.top();
    }
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
};



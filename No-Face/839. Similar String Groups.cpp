
class UnionFind
{
public: 
	UnionFind(int n) : count(n)
	{
		parent = vector<int>(count);
		for(int i = 0; i < count; i++)
			parent[i] = i;
	}
	
	int find(int x)
	{
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]);
	}
	
	void join(int x, int y)
	{
		int root_x = find(x);
		int root_y = find(y);
		
		if(root_x != root_y)
		{
			parent[root_x] = root_y;
			count--;
		}
	}
	
	int query() {return this->count;}
	
private:
	int count;
	vector<int> parent;
};


int numSimilarGroups(vector<string>& A)
{
	int size = A.size();
	
	UnionFind uf(size);
	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(isSimilar(A[i], A[j]))
			{
				uf.join(i, j);
			}
		}
	}
	
	return uf.query();
}


bool isSimilar(string lhs, string rhs)
{
	if(lhs == rhs) return true;
	int diff = 0;
	for(int i = 0; i < lhs.size(); i++)
	{
		if(lhs[i] != rhs[i] && ++diff > 2)
			return false;
	}
	return true;
}
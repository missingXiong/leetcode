

// matrix: id => coordinates; coordinates => id

74. Search a 2D Matrix
// time compexity: O(logM*N)
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.size() == 0) return false;
	
	int m = matrix.size();
	int n = matrix[0].size();
	int lo = 0, hi = m * n - 1;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		int row = mid / n;        // id => coordinates
		int col = mid % n;
		if(matrix[row][col] == target)
			return true;
		else if(matrix[row][col] < target)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return false;
}

240. Search a 2D Matrix 2 (row-wise and column-wise matrix)
// time complexity : O(M + N)
// from top right to bottom left
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.size() == 0) return false;
	
	int m = matrix.size();
	int n = matrix[0].size();
	int i = 0, j = n - 1;
	while(i < m && j >= 0)
	{
		if(matrix[i][j] == target)
			return true;
		else if(matrix[i][j] > target)
			j--;
		else
			i++;
	}
	return false;
}

// divide and conquer
/*
solution: 
(1) find middle element
(2) if middle > target 
	find in two parts: 
		1) from middle element to top right elements
		2) left columns(which numbers < middle.col)
(3) if middle < target
	find in two parts
		1) from middle element to top right elements
		2) under rows(which numbers > middle.row)

base case: if(i < 0 || i >= m || j < 0 || j >= m) return false;
recursively (1) - (3).
*/
bool recursion(vector<vector<int>>& matrix, int target,
				int brow, int erow, int bcol, int ecol)
{
	if(brow > erow || bcol > ecol) return false;
	// 如果不考虑以下两种情况会进入死循环
	if(brow == erow)
	{
		for(int j = bcol; j <= ecol; j++)
			if(matrix[brow][j] == target) return true;
		return false;
	}
	if(bcol == ecol)
	{
		for(int i = brow; i <= erow; i++)
			if(matrix[i][ecol] == target) return true;
		return false;
	}
	
	int p = brow + (erow - brow) / 2;
	int q = bcol + (ecol - bcol) / 2;
	if(matrix[p][q] == target) return true;
	else
	{
		int bFind = recursion(matrix, target, brow, p, q, ecol);
		if(matrix[p][q] > target)
			return bFind || recursion(matrix, target, brow, erow, bcol, q - 1);
		else
			return bFind || recursion(matrix, target, p + 1, erow, bcol, ecol);
	}
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.size() == 0) return false;
	int m = matrix.size();
	int n = matrix[0].size();
	
	return recursion(matrix, target, 0, m - 1, 0, n - 1);
}

























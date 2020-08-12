string tictactoe(vector<vector<int>>& moves)
{
	vector<vector<int>> row(2, vector<int>(3, 0));
	vector<vector<int>> col(2, vector<int>(3, 0));
	vector<int> diag1(2, 0);
	vector<int> diag2(2, 0);
	
	for(int i = 0; i < moves.size(); i++)
	{
		int id = i % 2;
		int r = moves[i][0];
		int c = moves[i][1];
		
		if(++row[id][r] == 3 || ++col[id][c] == 3 || (c + r == 2 && ++diag1[id] == 3) || (c == r && ++diag2[id] == 3))
			return id == 0 ? "A" : "B";
	}
	
	return moves.size() == 9 ? "Draw" : "Pending";
}

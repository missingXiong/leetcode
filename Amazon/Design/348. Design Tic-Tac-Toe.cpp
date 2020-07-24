

class TicTacToe 
{
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) 
	{
		size = n;
		diagonal = anti_diagonal = 0;
		row_judge.resize(n, 0);
		col_judge.resize(n, 0);
	}
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) 
	{
		int add = player == 1 ? 1 : -1;
		row_judge[row] += add;
		col_judge[col] += add;
		if(row == col) diagonal += add;
		if((row + col) == n - 1) anti_diagonal += add;
		if(abs(row_judge[row]) == size || abs(col_judge[col]) == size 
		   || abs(diagonal) == size || abs(anti_diagonal) == size)
			return player;
		else return 0;
	}
private:
	vector<int> row_judge;
	vector<int> col_judge;
	int size;
	int diagonal;
	int anti_diagonal;
};
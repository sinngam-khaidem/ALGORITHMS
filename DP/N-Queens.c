/* C program to solve N Queen Problem using backtracking */
#include <stdio.h>
#include <stdbool.h>
#define N 4

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed then return true */
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		/* Check if the queen can be placed on board[i][col] */
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;
			board[i][col] = 0; //backtrack
		}
	}
	/* If the queen cannot be placed in any row in this column col then return false */
	return false;
}

int main()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						          { 0, 0, 0, 0 },
						          { 0, 0, 0, 0 },
						          { 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
	}
  else{
    printSolution(board);
  }
	return 0;
}


#include <iostream>
#include "queens.h"
using namespace std;

// instance variable
int solutions = 0; // keeps trach of number of solutions

/*
 * Declares and initializes the "board," stored as a one-dimensional 
 *  array for convenience and facility. Then finds all solutions
 *  through eval_helper
 */
void eval(const int n) {

	int board[n * n];
	initialize_board(n, board);

	 eval_helper(n, 0, board);

	cout << "There are " << solutions << " solutions." << endl;
}

// Recursively finds the different solutions and prints them to cout
void eval_helper(const int n, int row, int board[]) {

	// checks if board is completed, prints board and moves on
	if(row >= n) {
		print_board(n, board);
		solutions++;
		return;
	}

	int col_good = 0; 	// indicates if column is empty in board
	int diags_good = 0; // indicates if diagonal is empty in board
	int index = -1; 	// saves repetitive calls to get_index

	/*
	 * For each column, checks if a queen may be placed in the 
	 *  respective location. If so, places a queen and continues 
	 *  to next row. After completing a board, it removes the queen
	 */
	for(int c = 0; c < n; c++) {
		col_good = check_col(n, c, board);
		diags_good = check_diags(n, row, c, board);
		index = get_index(n, row, c);

		if(!(col_good || diags_good)) {
			board[index] = 1;
			eval_helper(n, row+1, board);
		}

		board[index] = 0;
	}
}

// Returns the adjusted index to access (row, col) in the board
int get_index(const int n, int row, int col) {
	return row * n + col;
}

// Sets up an empty board
void initialize_board(const int n, int board[]) {
	for(int r = 0; r < n; r++) 
		for(int c = 0; c < n; c++)
			board[get_index(n, r, c)] = 0;

}

// Checks if the column col has a queen in it
int check_col(const int n, int col, int board[]) {
	for(int r = 0; r < n; r++)
		if(board[get_index(n, r, col)] == 1)
			return 1;

	return 0;
}

// Checks if the diagonals have any queens on them from (row, col)
int check_diags(const int n, int row, int col, int board[]) {
	for(int i = 1; i < n; i++) {
		if(row - i >= 0 && col - i >= 0 && board[get_index(n, row-i, col-i)] == 1)
			return 1;
		if(row - i >= 0 && col + i < n && board[get_index(n, row-i, col+i)] == 1)
			return 1;
		if(row + i < n && col - i >= 0 && board[get_index(n, row+i, col-i)] == 1)
			return 1;
		if(row + i < n && col + i < n && board[get_index(n, row+i, col+i)] == 1)
			return 1;
	}

	return 0;
}

// Prints the current board to cout
void print_board(const int n, int board[]) {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++)
			cout << board[get_index(n, r, c)] << " ";
		cout << endl;
	}
	cout << endl;
}


int main() {

	cout << "How many queens? ";

	int queens;
	cin >> queens;

	eval(queens);

	return 0;
}
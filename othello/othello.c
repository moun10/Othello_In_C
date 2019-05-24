//***************************************************
// Filename: othello.c
//
// template Author: N/A
// Author: N/A
//***************************************************

#include "othello.h"

//Variable for checking game over
//Becomes 1 when game over
int done = 0;

//NOTE gcc -Wall -std=c99 -o main *.c
//Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE])
{
	printf("\n");

	//Prints Board Nubers
	for (int i = 0; i < SIZE; i++)
	{
		printf((i == 0 ? "%5d" : "%3d"), i + 1);
	}
	printf("\n");

	//Prints Board Chars
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d", i + 1);
		for (int j = 0; j < SIZE; j++)
		{
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Initializes the board with start configuration of discs
void initializeBoard(char board[][SIZE])
{
	// Puts dashes over empty spaces
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = '-';
		}
	}

	//Puts four starting pieces
	board[3][3] = 'B';
	board[4][4] = 'B';
	board[4][3] = 'W';
	board[3][4] = 'W';
}

// Returns true if moving the disc to location row,col is valid;
// Else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
	//Int a will start off at 1
	//This is to check if enemy piece is one square over
	int a;

	//Checks out of bounds
	if (row > SIZE || col > SIZE)
	{
		return false;
	}

	//Checks empty
	if (board[row][col] != '-' || &board[row][col] == NULL )
	{
		//Return false if not emptry or is null
		return false;
	}
	else
	{
		//Checks if move is possible
		a = 1;
		//Going Up
		if (board[row][col - 1] != disc && &board[row][col - 1] != NULL && board[row][col - 1] != '-')
		{
			//Go until same disc found
			while(board[row][col - a] != disc)
			{
				a++;
				//return true if same disc found
				if(board[row][col - a] == disc)
				{
				return true;
				}
			}
		}
		a = 1;
		// Going Down
		if (board[row][col + 1] != disc && &board[row][col + 1] != NULL && board[row][col + 1] != '-')
		{
			//go until same disc found
			while(board[row][col + a] != disc)
			{
				a++;
				//return true if same disc found
				if(board[row][col + a] == disc)
				{
				return true;
				}
			}
		}
		a = 1;
		// Going Left
		if (board[row - 1][col] != disc && &board[row - 1][col] != NULL && board[row - 1][col] != '-')
		{
			//go until same disc found
			while(board[row - a][col] != disc)
			{
				a++;
				//return true if same disc found
				if(board[row - a][col] == disc)
				{
				return true;
				}
			}
		}
		a = 1;
		// Going Right
		if (board[row + 1][col] != disc && &board[row + 1][col] != NULL && board[row + 1][col] != '-')
		{
			//go until same disc found
			while(board[row + a][col] != disc)
			{
				a++;
				//return true if same disc found
				if(board[row + a][col] == disc)
				{
				return true;
				}
			}
		}
	}

	//Returns false if this fais if statements
	return false;
}

// Places the disc at location row,col
// Flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
		// Variable Tokens For Moving Around Board
		// Variable a checks if there is an enemy piece Up,Down,Left, or Right
		// Variable a moves until same piece found
		// This causes Variable b to start Flipping the pieces
		int a, b;
		a = 1;
		b = 1;


		//Going Up
		//Logic is Similar Up, Down, Left, and Right
		if (board[row][col - 1] != disc && &board[row][col - 1] != NULL && board[row][col - 1] != '-')
		{
			board[row][col] = disc;
			while(board[row][col - a] != disc && &board[row][col - a] != NULL && board[row][col - a] != '-')
			{
				a++;
				if(board[row][col - a] == disc){
				while(b < a){
				board[row][col - b] = disc;
				b++;
				}
				}
			}

		}
		a = 1;
		b = 1;
		// Going Down
		if (board[row][col + 1] != disc && &board[row][col + 1] != NULL && board[row][col + 1] != '-')
		{
			board[row][col] = disc;
			while(board[row][col + a] != disc && &board[row][col + a] != NULL && board[row][col + a] != '-')
			{
				a++;
				if(board[row][col + a] == disc)
				{
				//Start b token and palce new discs
				while(b < a){
				board[row][col + b] = disc;
				b++;
				}
				}
			}
		}
		a = 1;
		b = 1;
		// Going Left
		if (board[row - 1][col] != disc && &board[row - 1][col] != NULL && board[row - 1][col] != '-')
		{
			board[row][col] = disc;
			while(board[row - a][col] != disc && &board[row - a][col] != NULL && board[row - a][col] != '-')
			{
				a++;
				if(board[row - a][col] == disc)
				{
				//Start b token and palce new discs
				while(b<a){
				board[row - b][col] = disc;
				b++;
				}
				}
			}
		}
		a = 1;
		b = 1;
		// Going Right
		if (board[row + 1][col] != disc && &board[row + 1][col] != NULL && board[row + 1][col] != '-')
		{
			board[row][col] = disc;
			while(board[row + a][col] != disc && &board[row + a][col] != NULL && board[row + a][col] != '-')
			{
				a++;
				if(board[row + a][col] == disc)
				{
				//Start b token and palce new discs
				while(b<a)
				{
				board[row + b][col] = disc;
				b++;
				}
				}
			}
		}
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	// Checks each inidividual move with current color disc
	// Returns true if all avaliable
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			// Returns True if one valid move
			if (isValidMove(board, i, j, disc) == true){
				return true;
			}
		}
	}

	// Returns false if none found
	return false;
}

// Returns true if the board is fully occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{
	int i, j;
	//Counts empty pieces
	int empty = 0;
	// Searches for empty
	for(i=0; i<SIZE; i++)
	{
        for(j=0; j<SIZE; j++)
		{
						//Increase empty variable if empty space
            if(board[i][j] == '-')
                empty++;
		}
	}

	//If no empty space, returns true
	if(empty == 0){
		//Done means the game can not go on
		done = 1;
		return true;
	}
	//Returns false if empty found
	return false;
}

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{
	//Checks done to see if it is one, otherwhise it kept entering inf loop
	if (done == 1){
		return true;
	}
	//Returns false otherwhise
	return false;
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE])
{
	//Counts black
	int counterB;
	//Counts white
	int counterW;

	//Counts both pieces
	if (isGameOver(board))
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (board[i][j] == 'W')
				{
					counterW += 1;
				}
				if (board[i][j] == 'B')
				{
					counterB += 1;
				}
			}
		}

		//If black greater, returns black
		if (counterB > counterW)
		{
			done = 1;
			return BLACK;
		}
		//If white greater, returns white
		if (counterW > counterB)
		{
			done = 1;
			return WHITE;
		}
	}

	//Returns Empty if tie game
	return EMPTY;
}

// Source: https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/
// (Minmax implementation is different)
 
#include<bits/stdc++.h> 
using namespace std; 

struct Move 
{ 
	int row, col; 
}; 

char jugador = 'x', oponente = 'o'; 

bool isMovesLeft(char tablero[3][3]) 
{ 
	for (int i = 0; i<3; i++) 
		for (int j = 0; j<3; j++) 
			if (tablero[i][j]=='_') 
				return true; 
	return false; 
} 

int evaluartablero(char b[3][3]) 
{ 
	for (int row = 0; row<3; row++) 
	{ 
		if (b[row][0]==b[row][1] && 
			b[row][1]==b[row][2]) 
		{ 
			if (b[row][0]==jugador) 
				return +10; 
			else if (b[row][0]==oponente) 
				return -10; 
		} 
	} 

	for (int col = 0; col<3; col++) 
	{ 
		if (b[0][col]==b[1][col] && 
			b[1][col]==b[2][col]) 
		{ 
			if (b[0][col]==jugador) 
				return +10; 

			else if (b[0][col]==oponente) 
				return -10; 
		} 
	} 

	if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) 
	{ 
		if (b[0][0]==jugador) 
			return +10; 
		else if (b[0][0]==oponente) 
			return -10; 
	} 

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) 
	{ 
		if (b[0][2]==jugador) 
			return +10; 
		else if (b[0][2]==oponente) 
			return -10; 
	} 

	return 0; 
} 

int minimax(char tablero[3][3], int depth, bool isMax) 
{ 
	int score = evaluartablero(tablero);
	if (depth == 4)
		return score;
		
	if (score == 10) 
		return score; 
	if (score == -10) 
		return score; 
	if (isMovesLeft(tablero)==false) 
		return 0; 
	if (isMax) 
	{ 
		int eval = -10000; 
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 
				if (tablero[i][j]=='_') 
				{ 
					tablero[i][j] = jugador; 

					eval = max( eval, 
						minimax(tablero, depth+1, !isMax) ); 

					tablero[i][j] = '_'; 
				} 
			} 
		} 
		return eval; 
	} 

	else
	{ 
		int eval = 1000; 
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 
				if (tablero[i][j]=='_') 
				{ 
					tablero[i][j] = oponente; 

					eval = min(eval, 
						minimax(tablero, depth+1, !isMax)); 
					tablero[i][j] = '_'; 
				} 
			} 
		} 
		return eval; 
	} 
} 

Move findBestMove(char tablero[3][3]) 
{ 
	int evalVal = -1000; 
	Move evalMove; 
	evalMove.row = -1; 
	evalMove.col = -1; 

	for (int i = 0; i<3; i++) 
	{ 
		for (int j = 0; j<3; j++) 
		{ 
			if (tablero[i][j]=='_') 
			{ 
				tablero[i][j] = jugador; 

				int moveVal = minimax(tablero, 0, false); 

				tablero[i][j] = '_'; 

				if (moveVal > evalVal) 
				{ 
					evalMove.row = i; 
					evalMove.col = j; 
					evalVal = moveVal; 
				} 
			} 
		} 
	} 

	printf("The value of the eval Move is : %d\n\n", 
			evalVal); 

	return evalMove; 
} 

int main() 
{ 
	char tablero[3][3] = 
	{ 
		{ 'x', 'o', 'x' }, 
		{ 'o', 'o', 'x' }, 
		{ '_', '_', '_' } 
	}; 

	Move evalMove = findBestMove(tablero); 

	printf("The Optimal Move is :\n"); 
	printf("ROW: %d COL: %d\n\n", evalMove.row, evalMove.col ); 
	return 0; 
} 


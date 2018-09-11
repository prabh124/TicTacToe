#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Initialize functions that are used within the code
int checkWinner(char w);
void displayBoard(char array[]);
bool moveIsValid(char array[], int move);
int winChecker(char array[]); 


	int main()
	{
			//Seed random time slots to allow for true randomization later on in the program
			srand(time(NULL));
	
			//This allows for the first chosen player to be randomized
			int turnCounter = rand() % 3;		
			
			int move;			
			int totalMoves = 0;
			//Turns are currently left blank, they will be assigned to either "x" or "o" depending on the turnCounter
			char playerTurn = ' ';
			char computerTurn = ' ';
			
			//Assign values to the board
			char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

			//While loop that continues until the max amount of turns have been reached, or if someone has won
			while (winChecker(board) == 0 && totalMoves < 9)
			{
					//If no one has gone yet, display the board 
					if (totalMoves == 0)
					{
						cout << "\nTic Tac Toe! Can you beat the computer?\n";
						displayBoard(board);
					}
							//If the turn counter is set to 1, it is the players turn
							if (turnCounter == 1) 
							{

								//if the total moves mod 2 is 0, the player has the first turn and becomes x, else the player is o
								if (!(totalMoves % 2))
								{
									playerTurn = 'x';
									
									//Show the player what letter they are
									if (totalMoves < 2)
									cout << "You are: " << playerTurn << "'s! " << endl;
								}
				
								else
								{
									playerTurn = 'o';
								
									//Show the player what letter they are
									if (totalMoves < 2)
									cout << "You are: " << playerTurn << "'s! " << endl;
								}
								
								cout << "It's your turn!" << endl;
								
								//Request the move
								cout << "Enter the spot you want to move to" << endl;
								cin >> move;
				
								//If the move is not valid, keep requesting an input until it is
								while ((moveIsValid(board, move) == false) || (move <= 0) || (move >= 10))

								{
									cout << "Invalid move! Please enter a number that has not been chosen as of yet!  "; 
									cin >> move;
					
								}
								//Set board at [move - 1] = either "x" or "o" depending on the player turn
								board[move - 1] = playerTurn;
				
							}

							//If the turnCounter is 2, it is the computers turn
							else 
							{

								//If the computer goes first, let the player know
								if (totalMoves == 0)
								{
									cout << "The computer is going first! Lets see what it does! " << endl;
								}
				
								//if the total moves mod 2 is 0, the computer has the first turn and becomes x, else the computer is o
								if (!(totalMoves % 2))
								{
									computerTurn = 'x';
								}

								else
								{
									computerTurn = 'o';
								}
								// Computer selects random square
				
								move = 1 + rand() % 9;
				
								//If the move is not valid, seed another move until it is
								while ((moveIsValid(board, move) == false) || (move <= 0) || (move >= 10))
								{
									move = 1 + rand() % 9;
					
								}
								//Set board at [move - 1] = either "x" or "o" depending on the computers turn
								board[move - 1] = computerTurn;
				
								cout << "\nThe computer played number " << move << endl;
		
							}

				

				// Add 1 to totalMoves, so that the while loop will break if the game is a tie
				totalMoves++;
				
				//Algorithm for changing players automatically each turn
				turnCounter++;
				if (turnCounter > 2)
				{
					turnCounter = 1;
				}
		
				displayBoard(board);

			}

	// Show the board
	

	//Switch statement that checks who won, and outputs the winner
	switch (winChecker(board)) 
	{
		case 1:

			//If the computer did not go first and the winChecker returns 1, then the player has won
			if (computerTurn != 'x')
				cout << "You have won the game!" << endl;

			//Else the computer wins
			else
				cout << "The computer has won the game!" << endl;
			break;
		
		case 2:
			
			//If the computer did not go second and the winChecker returns 2, then the player has won. 
			if (computerTurn != 'o')
				cout << "You have won the game!" << endl;
			
			//Else the computer wins
			else
				cout << "The computer has won the game!" << endl;
			break;
		
		default:

			//If no one wins, then the game is a draw
			cout << "It's a tie game!" << endl;
			break;
	}

	
 }

		/* FUNCTION SEGMENT */

		//Function used to print the board to the console
		void displayBoard(char array[])
		{
			cout << endl;
			cout << array[0] << " | " << array[1] << " | " << array[2] << endl;
			cout << "--|---|--" << endl;
			cout << array[3] << " | " << array[4] << " | " << array[5] << endl;
			cout << "--|---|--" << endl;
			cout << array[6] << " | " << array[7] << " | " << array[8] << endl;
			cout << endl;
		}

		//Check if the move done was valid
		bool moveIsValid(char array[], int move)
		{
			//If the inputted number has not already been taken in a previous turn, return true.
			if ((array[move - 1] != 'x') && (array[move - 1] != 'o'))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		//This is a helper function to reduce code in winChecker.
		//It checks whether "x", or "o" won, or neither
		int checkWinner(char w)
		{
			if (w == 'x') {
				return 1;
			}
			else {
				return 2;
			}
		}

		int winChecker(char array[])
		{
			//The first 3 if statements check for a winner in the horizontal
			//The Second 3 if statements check for a winner in the vertical
			//The last two if statements check for a winner in the diagonal
			//If none of these are satisfied, the game is a tie
			if (array[0] == array[1] && array[1] == array[2]) 
			{
				return checkWinner(array[0]);
			}

			if (array[3] == array[4] && array[4] == array[5]) 
			{
				return checkWinner(array[3]);
			}

			if (array[6] == array[7] && array[7] == array[8]) 
			{
				return checkWinner(array[6]);
			}

			if (array[0] == array[3] && array[3] == array[6]) 
			{
				return checkWinner(array[0]);
			}

			if (array[1] == array[4] && array[4] == array[7]) 
			{
				return checkWinner(array[1]);
			}
			if (array[2] == array[5] && array[5] == array[8]) 
			{
				return checkWinner(array[2]);
			}

			if (array[0] == array[4] && array[4] == array[8]) 
			{
				return checkWinner(array[0]);
			}

			if (array[2] == array[4] && array[4] == array[6]) 
			{
				return checkWinner(array[2]);
			}
	
			return 0;
		}




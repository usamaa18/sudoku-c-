#include "verify_full.h"
#include "create_full.h"
#include "solve_brute.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
 #include <limits>

using namespace std;

void disp(vector< vector<int> > &board){
	for (auto i : board){
		for(auto j : i)
			cout << j << " ";
		cout << "\n";
	}
}

vector< vector<int> > inputBoard(){
	vector< vector<int> > board(9);
	int n;
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			cin >> n;
			board[i].push_back(n);
		}
	}
	return board;
}

int main() {
	srand(time(0));  // Initialize random number generator.
	int option;
	bool stop = false;
	while (!stop){
		cout << "*******************************" << endl;
		cout << "Welcome to Sudoku. Please select one of the following options!" << endl;
		cout << "1. Generate an unsolved Sudoku" << endl;
		cout << "2. Verify a solved Sudoku" << endl;
		cout << "3. Are you stuck? Get the solved solution to the Sudoku" << endl;
		cout << "4. Generate a random solved Sudoku" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice and hit enter: ";

		cin >> option;

		switch (option) {

			
			case 1:{
					cout << "Select difficulty (1-3): ";
					int difficulty;
					cin >> difficulty;
					auto board = generate();
					deleteClues(20+(difficulty-1)*5,board);
					cout << "Unsolved Sudoku: \n";
					disp(board);
					break;
					}
			case 2:{cout << "Enter a solved sudoku: "<< endl;
					auto board = inputBoard();
					if (check_everything(board))
						cout << "Good Job! You have correctly solved the Sudoku! \n";
					else
						cout << "Unfortunately, this is not valid! \n";
					break;
					}
			case 3:{cout << "Enter an unsolved sudoku: "<< endl;
					auto board = inputBoard();
					if (solve(board)){
						cout << "Solved Sudoku: \n";
						disp(board);
					}
					else
						cout << "Unfortunately, this is an unsolvable Sudoku\n";
					break;
					}
			case 4:	{auto board = generate();
					cout << "Solved Sudoku: \n";
					disp(board);
					break;
					}
			case 5:{cout << "Thank you for solving Sudoku! We hope you come next time!" << endl;
					stop = true;
					break;
					}
			default:{
			cout << "Not a Valid Selection"<< endl;
			cin >> option;
			break;
		}
		}
		cout << "PRESS ENTER TO CONTINUE\n";
		cin.ignore();
		cin.ignore();
	}
	return 0;
}

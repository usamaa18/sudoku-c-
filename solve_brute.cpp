#include "solve_brute.h"
#include "create_full.h"

// solves the actual sudoku using depth-first brute force algorithm. Returns whether it is solvable or not
bool solve (vector < vector<int> >& board){
	int emptySlotN = 0; // number of empty slots in sudoku

	vector< vector <int> > sq_id = gen_sq_id();

	vector < vector <int> > rows(9); // 9 different rows
	vector < vector <int> > columns(9); // 9 columns
	vector < vector <int> > squares(9); // 9 3x3 squares
	vector < vector <int> > editable(9); // matrix to indicate which positions in sudoku are editable and which are fixed
	
	// fill in the above variables
	for (int i=0; i<9; i++)
		for (int j=0; j<9; j++){
			int n = board[i][j];
			if (n != 0){
				rows[i].push_back(n);
				columns[j].push_back(n);
				squares[sq_id[i][j]].push_back(n);
				editable[i].push_back(-1);
			}
			else
				editable[i].push_back(emptySlotN++);
		}

	// 9 possible values
	const vector <int> oneToNine{1,2,3,4,5,6,7,8,9};
	vector < vector <int> > possibleValues(emptySlotN, oneToNine);

	for (int i=0; i<9; i++){
		vector <int> sublist;
		for (int j=0; j<9; j++){
			if (editable[i][j] != -1){

			// rcs (Rows, Columns, Squares) holds the combined numbers that cannot be tried at a given (i,j) square
			set <int> rcs;
			rcs.insert(rows[i].begin(), rows[i].end());
			rcs.insert(columns[j].begin(), columns[j].end());
			rcs.insert(squares[sq_id[i][j]].begin(), squares[sq_id[i][j]].end());

			for (int item : rcs){
				VALID_VAL.erase(std::remove(VALID_VAL.begin(), VALID_VAL.end(), item), VALID_VAL.end());
				
				// if num of valid options are 0, backtrace to last changed number and try the next option
				if (VALID_VAL.empty()){

					VALID_VAL = {1,2,3,4,5,6,7,8,9};

					bool goBack = true;
					while (goBack){
						do {
							if (j>0)
								j--;
							else
								if (i>0){
									i--;
									j = 8;
								}
								else{
									return false;
								}
						}while (editable[i][j] == -1);

						// remove the old additions to these variables
						rows[i].pop_back();
						columns[j].pop_back();
						squares[sq_id[i][j]].pop_back();
						VALID_VAL.pop_back();
						board[i][j] = 0;

						// ensure valid variable list is reset
						if (VALID_VAL.empty())
							VALID_VAL = {1,2,3,4,5,6,7,8,9};
						else
							goBack = false;
					}
				}
			}
			
			// push tried options to all variables
			int n = VALID_VAL.back();
			board[i][j] = n;
			rows[i].push_back(n);
			columns[j].push_back(n);
			squares[sq_id[i][j]].push_back(n);

			rcs.clear();
			}

		}
	}

	return true;

}


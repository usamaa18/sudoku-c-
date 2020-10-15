#include "create_full.h"

// used by gen_sq_id()
int reduce (int x) {
	int index = 0;
	if  (x <= 2)
		index = 0;
	else if (x<=5)
		index = 1;
	else if (x<=8)
		index = 2;
	return index;
}

// maps all 81 squares in sudoku to one of 9 major 3x3 squares
vector < vector <int> > gen_sq_id(){
	vector < vector <int> > sq_id;
	for (int i=0; i<9; i++){
		vector <int> sub;
		for (int j=0; j<9; j++){

			int indexJ = reduce(j);
			int indexI = reduce(i);

			int value = indexJ + (3*indexI);
			sub.push_back(value);
		}
		sq_id.push_back(sub);
	}
	return sq_id;
}

// delete some clues based on difficuly chosen. uses diagonal deletion to ensure unique solution
void deleteClues (int numClues, vector < vector<int> >& board){

	for (int i=0; i<numClues; i++){
		int x = rand() % 9;
		int y = rand() % 9;
		board[x][y] = 0;
		board[8-x][8-y] = 0; // diagonal element access
	}
}

// generates random valid solved sudoku
vector < vector<int> > generate(){

	// keeps track of number of attempts
	int attempts = 0;

	vector< vector <int> > sq_id = gen_sq_id();

	vector < vector<int> > board;

	bool verify = false;

	// not really necessary to check, but just an extra measure
	while (!verify){

		// these keep track of numbers that have already been used in each row, column and 3x3 square
		vector < set <int> > rows(9);
		vector < set <int> > columns(9);
		vector < set <int> > squares(9);

		board.clear();

		int n;

		for (int i=0; i<9; i++){
			// basically a row to be added to board, named sublist to avoid confusion with "rows"
			vector <int> sublist;
			int j;
			for (j=0; j<9; j++){

				// 9 possible numbers stored in an attempt pool
				unordered_set <int> pool = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				
				// combine rows, columns and squares into rcs
				set <int> rcs;
				rcs.insert(rows[i].begin(), rows[i].end());
				rcs.insert(columns[j].begin(), columns[j].end());
				rcs.insert(squares[sq_id[i][j]].begin(), squares[sq_id[i][j]].end());

				// remove impossible numbers from attempt pool
				for (int item : rcs){
					pool.erase(item);
				}

				n = 0;
				if (pool.size() == 0){
					//cout << "empty";
					break;
				}

				// randomly pick an element from attempt pool
				int r = rand() % pool.size();
				auto it = pool.begin();
				advance(it, r);
				n = *it;

				// insert that element into corresponding rows, columns and squares
				rows[i].insert(n);
				columns[j].insert(n);
				squares[sq_id[i][j]].insert(n);

				// insert into current row
				sublist.push_back(n);
			}
			if (n == 0){
				break;
			}
			// insert a full valid new row into board
			board.push_back(sublist);
		}
		attempts++;
		if (n!=0)
			verify = true;
	}
	//cout << "Attempts: " << attempts << "\n";
	return board;
}

#ifndef __SOLVE_BRUTE_H
#define __SOLVE_BRUTE_H

#include <vector>
#include <cstdlib>  // For srand() and rand()
#include <set>
#include <iterator>
#include <iostream>
#include <algorithm>

#define VALID_VAL possibleValues[editable[i][j]]

using namespace std;

// solves the actual sudoku using depth-first brute force algorithm. Returns whether it is solvable or not
bool solve (vector < vector<int> >& board);


#endif

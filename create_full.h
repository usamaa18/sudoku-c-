#ifndef __CREATE_FULL_H
#define __CREATE_FULL_H

#include <vector>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <unordered_set>
#include <set>
#include <iterator>
#include <iostream>

using namespace std;

// used by gen_sq_id()
int reduce (int x);

// maps all 81 squares in sudoku to one of 9 major 3x3 squares
vector < vector <int> > gen_sq_id();

// delete some clues based on difficuly chosen. uses diagonal deletion to ensure unique solution
void deleteClues (int numClues, vector < vector<int> >& board);

// generates random valid solved sudoku
vector < vector<int> > generate();



#endif

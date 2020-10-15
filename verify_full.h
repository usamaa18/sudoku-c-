#ifndef __FULL_VERIFY_H
#define __FULL_VERIFY_H

#include <iostream>
#include <set>
#include <vector>

using namespace std;

//checks for duplicates in row
bool check_row(int row, vector< vector<int> > &board);

//checks for duplicates in columns
bool check_col(int col, vector< vector<int> > &board);

//checks for duplicates in 3x3 squares
bool check_squares(vector< vector<int> > &board);

//checks if all conditions are met
bool check_everything (vector< vector<int> > &board);


#endif

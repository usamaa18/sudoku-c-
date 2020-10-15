#include "verify_full.h"

//checks for duplicates in row
bool check_row(int row, vector< vector<int> > &board){
  for (int i=0;i<9;i++){
    for (int j=i+1; j<9; j++){
      if(board[row][i]==board[row][j]){
        //cout << "row is false" << endl;
        return false;
      }
    }
  }
  //cout << "row is true" << endl;
  return true; 
}

//checks for duplicates in columns
bool check_col(int col, vector< vector<int> > &board){
  for (int i=0; i<9; i++){
    for (int j=i+1; j<9; j++){
      if(board[i][col]==board[j][col]){
        //cout << "col is false" << endl;
        return false;
      }
    }
  }
  //cout << "col is true" << endl;
  return true; 
}

//checks for duplicates in 3x3 squares
bool check_squares(vector< vector<int> > &board){
  for(int row = 0; row < 9; row = row + 3){
    for(int col = 0; col < 9; col = col + 3){
      set<int> test;
      for(int r = row; r < row + 3; r++){
        for(int c = col; c < col + 3; c++){
          if(test.insert(board[r][c]).second == false){
            //cout << "square is false" << endl;
            return false;
          }
        }
      }    
    }
  }
  //cout << "square is true" << endl;
  return true;
}


//checks if all conditions are met
bool check_everything (vector< vector<int> > &board){

  bool rows = true; //row check
  bool columns = true; //col check
  bool squares = true; //3x3 square check
  
  //row check
  for (int i=0; i<9; i++){
    if (check_row(i, board) == false){
      //cout << "x is false" << endl;
      rows = false;
    } 
  }

  //column check
  for (int i=0; i<9; i++){
    if (check_col(i, board) == false){
      //cout << "y is false" << endl;
      columns = false;
    } 
  }
  
  //3x3 square check
  if (check_squares(board) == false){
    //cout << "z is false" << endl;
    squares = false;
  }

  if (rows == false || columns == false || squares == false){
    return false;
  }

  return true;
}
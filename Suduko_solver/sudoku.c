#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------

// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
/* Mahip Deora 2019
 * to do this mp i broke it up into 2 main parts check and slove
 * first i would check if there were any empty cells is so then i move on with my steps
 * in check if the number that i made exsited somewhere else in the board
 * if it did then i would have to move the number up by 1
 * if the number was vaild then i would store it into the array
 * then i would call the fucntion again to move onto the next board slot, if that failed it would return a 0
 * if a 0 was returned then i would need to edit the pervious slot
 * based on this i was able to slove the mp


 */
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  int n = 0;
  // this part checks if the num (val) exsit in the same row as current slot
  while ( n < 9) {
    if ( val == sudoku[i][n]) {
      return 1;
    }
      n += 1;
  }
    
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);
  // this part check if the num (val) exsit in the same col as j
  // BEG TODO
  int n = 0;
  while ( n < 9) {
    if ( val == sudoku[n][j]) {
      return 1;
      
    }
      n += 1;
  }
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
  // this part checks if the num (val) exsit somewhere else in thar 3x3 matrix
  assert(i>=0 && i<9);
  int r = 0, c = 0;
  for ( r = 0; r < 3; r++) { // looping through 3 rows of the array
    c = 0;
    for ( c = 0; c < 3; c++) { // looping through 3 cols of the array 
      if (sudoku[(i-(i%3)) + r][(j-(j%3)) + c] == val) { // finds the start of the 3x3 array using math 
        return 1;
       
      }
    }
  }
  // BEG TODO
  
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {
  // checks if the number (val) deosnt exsit else where
  assert(i>=0 && i<9 && j>=0 && j<9);
  int test1 = is_val_in_3x3_zone(val,i,j,sudoku);
  int test2 = is_val_in_col(val,j,sudoku);
  int test3 = is_val_in_row(val,i,sudoku);
  // BEG TODO
  if ( test1 == 0  && test2 == 0  && test3  == 0) {
    return 1;
  }
  return 0;
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
  int row, col, fill = 0;
  int  n,hold = 0;
  // this part finds a row and col where the slot is empty, this then breaks out of the loop and stores value of row and col 
  for(row = 0; row < 9; row ++) {
    for(col = 0; col < 9; col ++) {
      if (sudoku[row][col] == 0) {
	      fill = 1;
        hold = 1 ;
        break;
      }
    }
    if ( hold == 1) {
      break;
    }
  }
  
  // if the array is full return a 1
  if ( fill == 0) {
    return 1;
  } else {
    if (sudoku[row][col] == 0) {
      // asgin a val for the empty slot
      for (n = 1; n <= 9; n++) {
      	if(is_val_valid(n,row,col,sudoku) == 1) {
	           sudoku[row][col] = n;
             // make sures the nexr slot is vaild
	           if(solve_sudoku(sudoku) == 1) {
	          return 1;
	  }
          // if a false was returned then set the value back to 0
	        sudoku[row][col] = 0;
	  
	}
      }
    }
  }
  return 0;
}
// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}






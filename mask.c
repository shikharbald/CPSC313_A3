#include <stdio.h>
#include "mask.h"
#include <stdlib.h>

// When completed this file will contain several versions of the
// mask() function and conditional compilation will be used to
// determine which version runs.  Each version will be named mask1,
// mask2, and so on. To select the version of the mask function to
// use, change the following declaration to the version of the mask()
// to be used.  All versions of mask() must produce a correct result.

// The provided Makefile also includes the possibility of creating an
// executable called "timemask-maskN" (replacing maskN with any
// version you'd like to test). You may compile it with "make
// timemask-maskN" then run "./timemask-maskN".

#ifndef MASK_VERSION
#define MASK_VERSION mask14
#endif

// You are only allowed to change the contents of this file with
// respect to improving the performance of this program. You may not
// change the data structure for each image or the parameters for the
// function mask. You may, however, change the structure of the code
// and the types/implementation of local variables (col, row, weight,
// etc.).


// You are required to document the changes you make in the README.txt
// file. For each entry in the README.txt file there is to be a
// version of the matching mask() function here such that the markers
// can see, and run if needed, the actual code that you used to
// produce your results for the logged change to the mask function.

static inline long mask0(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
  return baseMask(oldImage, newImage, rows, cols);
}

// For each version of mask you are testing duplicate the function
// below, rename it to a different name, and make your changes. To use
// the new version, change the #define above to use the current version.

static inline long mask1(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
   printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++){ 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  }
  // Count the cells to the top left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (i = 0; i < cols; i++) {
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the top right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;

 
}

static inline long mask2(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
  
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (i = 0; i < cols; i++) {
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the top right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
  
}

long mask3(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
 
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
    
  // Count the cells to the top right 
for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
 
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.





}
long mask4(long oldImage[N][N], long newImage[N][N], int rows, int cols) {

 
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.

}

long mask5(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
  
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //5 Count the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 
}


long mask6(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
   
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //5 Count the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //6 Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //7 Count the cells to the bottom left
 for (j = 0; j < rows - 1; j++){
   row = j + 1;
   for (i = 1; i < cols; i++){
     col = i - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 

}


long mask7(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
   
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //5 Count the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //6 Count the cells to the immediate right
  for (j = 0; j < rows; j++) {
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //7 Count the cells to the bottom left
 for (j = 0; j < rows - 1; j++){
   row = j + 1;
   for (i = 1; i < cols; i++){
     col = i - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 




}


long mask8(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
   
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //5 Count the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //6 Count the cells to the immediate right
  for (j = 0; j < rows; j++) {
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //7 Count the cells to the bottom left
 for (j = 0; j < rows - 1; j++){
   row = j + 1;
   for (i = 1; i < cols; i++){
     col = i - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //8 Count the cells immediately below
 for (j = 0; j < rows - 1; j++) {
      row = j + 1;
  for (i = 0; i < cols; i++) {
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //9 Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 




}

long mask9(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
   
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //5 Count the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //6 Count the cells to the immediate right
  for (j = 0; j < rows; j++) {
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //7 Count the cells to the bottom left
 for (j = 0; j < rows - 1; j++){
   row = j + 1;
   for (i = 1; i < cols; i++){
     col = i - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //8 Count the cells immediately below
 for (j = 0; j < rows - 1; j++) {
      row = j + 1;
  for (i = 0; i < cols; i++) {
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //9 Count the cells to the bottom right
  for (j = 0; j < rows - 1; j++) {
    row = j + 1;
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 

}


long mask10(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
   
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //5 Count the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //6 Count the cells to the immediate right
  for (j = 0; j < rows; j++) {
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //7 Count the cells to the bottom left
 for (j = 0; j < rows - 1; j++){
   row = j + 1;
   for (i = 1; i < cols; i++){
     col = i - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //8 Count the cells immediately below
 for (j = 0; j < rows - 1; j++) {
      row = j + 1;
  for (i = 0; i < cols; i++) {
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //9 Count the cells to the bottom right
  for (j = 0; j < rows - 1; j++) {
    row = j + 1;
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
 for (j = 0; j < rows; j++){
  for (i = 0; i < cols; i++){
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }}
  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
   
}

long mask11(register long oldImage[N][N],register long newImage[N][N], int rows, int cols) {
   
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  register int i, j;
  register int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
    }
  
  // Count the cells to the top left
 for (j = 1; j < rows; j++){ 
    row = j - 1;
  for (i = 1; i < cols; i++) {
    col = i - 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  // Count the cells immediately above
  for (j = 1; j < rows; j++){ 
  for (i = 0; i < cols; i++) {
      row = j - 1;
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //4 Count the cells to the top right
 for (j = 1; j < rows; j++) {
  row = j-1;  
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
     newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
 


//the cells to the immediate left
for (j = 0; j < rows; j++) {
  for (i = 1; i < cols; i++) {
    col = i - 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //6 Count the cells to the immediate right
  for (j = 0; j < rows; j++) {
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[j][col];
      weight[j][i]++;
    }
  }
  
  //7 Count the cells to the bottom left
 for (j = 0; j < rows - 1; j++){
   row = j + 1;
   for (i = 1; i < cols; i++){
     col = i - 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }
  
  //8 Count the cells immediately below
 for (j = 0; j < rows - 1; j++) {
      row = j + 1;
  for (i = 0; i < cols; i++) {
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
  }
  
  //9 Count the cells to the bottom right
  for (j = 0; j < rows - 1; j++) {
    row = j + 1;
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
      newImage[j][i] += oldImage[row][col];
      weight[j][i]++;
    }
  }

  // Produce the final result
 for (j = 0; j < rows; j++) 
  for (i = 0; i < cols; i++){
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
/*   printf("%s %d\n%s %d\n %s %d\n %s %d\n %s %d\n%s %d\n %s %d\n %s %d\n%s %d\n","weight1:"
,weight[0][0],"weight2:",weight[0][2],"weight3:",weight[0][cols-1],"weight4:",weight[1][0],"weight5:",weight[1][2],"weight6:",weight[1][cols-1],"weight7:",weight[rows-1][0],"weight8:",weight[rows-1][2],"weight9:",weight[rows-1][cols-1]);*/  
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 
}


static inline long mask12(register long oldImage[N][N],register long newImage[N][N], int rows, int cols) {
  
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  register int i, j;
  register int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++){ 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
}
 for (i = 1; i < cols; i++) {
      newImage[j][i-1] += oldImage[j][i];
      weight[j][i-1]++;
  
      newImage[j][i] += oldImage[j][i-1];
      weight[j][i]++;
    } 
}  
  //2 and 9  merged, Count the cells to the top left
  for (j = 1; j < rows; j++){
   row = j - 1;
    for (i = 1; i < cols; i++) {
     newImage[j][i] += oldImage[row][i-1];
      weight[j][i]++;   
    }
     for (i = 0; i < cols; i++) {
      newImage[j][i] += oldImage[row][i];
      weight[j][i]++;
    }
      for (i = 0; i < cols - 1; i++) {
     newImage[j][i] += oldImage[row][i+1];
      weight[j][i]++;
    }
 }
  
  
  
 //7 and  8 loop merged, Count the cells to the bottom left
 for(j = 0; j < rows - 1; j++){
   row = j + 1;
     for (i = 1; i < cols; i++){
      col = i - 1;
       newImage[j][i] += oldImage[row][col];
       weight[j][i]++;
       newImage[j][col] += oldImage[row][i];
       weight[j][col]++;
   }
     for (i = 0; i < cols; i++) {
       newImage[j][i] += oldImage[row][i];
       weight[j][i]++;
    }
  }
  

  // Produce the final result
 for (j = 0; j < rows; j++){
    for (i = 0; i < cols; i++){
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  }
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 
}



static inline long mask13(register long oldImage[N][N], register long newImage[N][N],  int rows, int cols) {
  
 
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  register int i, j;
  register int col, row;
  register long check = 0;

  register long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image 
for (j = 0; j < rows; j++){ 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
      weight[j][i] = WEIGHT_CENTRE;
}
 for (i = 1; i < cols; i++) {


      newImage[j][i-1] += oldImage[j][i];
      weight[j][i-1]++;
  
      newImage[j][i] += oldImage[j][i-1];
      weight[j][i]++;
   
    } 
}  
  //2 and 9  merged, Count the cells to the top left
  for (j = 1; j < rows; j++){
   row = j - 1;
   col= cols -1;
     newImage[j][col] += oldImage[row][col-1];
     weight[j][col] += 2;   
     newImage[j][col] += oldImage[row][col];
     weight[j][0] += 2;
     newImage[j][0] += oldImage[row][0];
     newImage[j][0] += oldImage[row][1];

         
    for (i = 1; i < cols-1; i++) {
     newImage[j][i] += oldImage[row][i-1];
      weight[j][i] += 3;  
     newImage[j][i] += oldImage[row][i];
     newImage[j][i] += oldImage[row][i+1];
      
    }
           
 }
  
  
  
 //7 and  8 loop merged, Count the cells to the bottom left
 for(j = 0; j < rows - 1; j++){
   row = j + 1;
     for (i = 1; i < cols; i++){
      col = i - 1;
       newImage[j][i] += oldImage[row][col];
       weight[j][i] += 2;
       newImage[j][i] += oldImage[row][i];
        newImage[j][col] += oldImage[row][i];
        weight[j][col]++;
   }
       newImage[j][0] += oldImage[row][0];
       weight[j][0]++;
  }
  

  // Produce the final result
 for (j = 0; j < rows; j++){
    for (i = 0; i < cols; i++){
      newImage[j][i] = newImage[j][i] / weight[j][i];
      check += newImage[j][i];
    }
  }
  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 

}

static inline long mask14(register long oldImage[N][N], register long newImage[N][N],  int rows, int cols) {
  
 
  printf("Here we come jobs");
  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
  register int i, j;
  register int col, row;
  register long check = 0;


  
  //initialize the new image 
for (j = 0; j < rows; j++){ 
  for (i = 0; i < cols; i++){
      newImage[j][i] = WEIGHT_CENTRE * oldImage[j][i];
}
 for (i = 1; i < cols; i++) {


      newImage[j][i-1] += oldImage[j][i];
  
      newImage[j][i] += oldImage[j][i-1];
      
  } 
}  
  //2 and 9  merged, Count the cells to the top left
  for (j = 1; j < rows; j++){
   row = j - 1;
   col= cols -1;
     newImage[j][col] += oldImage[row][col-1];
     newImage[j][col] += oldImage[row][col];
     
     newImage[j][0] += oldImage[row][0];
     newImage[j][0] += oldImage[row][1];

         
    for (i = 1; i < cols-1; i++) {
     newImage[j][i] += oldImage[row][i-1];
     newImage[j][i] += oldImage[row][i];
     newImage[j][i] += oldImage[row][i+1];
      
    }
           
 }
  
  
  
 //7 and  8 loop merged, Count the cells to the bottom left
 for(j = 0; j < rows - 1; j++){
   row = j + 1;
     for (i = 1; i < cols; i++){
      col = i - 1;
       newImage[j][i] += oldImage[row][col];
       newImage[j][i] += oldImage[row][i];
        newImage[j][col] += oldImage[row][i];
        
   }
       newImage[j][0] += oldImage[row][0];
  }
  

  // Produce the final result
 for (j = 1; j < rows-1; j++){
    for (i = 1; i < cols-1; i++){
      newImage[j][i] = newImage[j][i] / 12;
      check += newImage[j][i];
    }
  }
 
    for (i = 1; i < cols-1; i++){
      newImage[0][i] = newImage[0][i] / 9;
      check += newImage[0][i];
    }
 
    for (i = 1; i < cols-1; i++){
      newImage[cols-1][i] = newImage[cols-1][i] / 9;
      check += newImage[cols-1][i];
    }

  for (j = 1; j < rows-1; j++){
      newImage[j][0] = newImage[j][0] / 9;
      check += newImage[j][0];
    }


  for (j = 1; j < rows-1; j++){
      newImage[j][cols-1] = newImage[j][cols-1] / 9;
      check += newImage[j][cols-1];
    }

    j = cols -1;
    i = rows -1;

   newImage[0][0] = newImage[0][0] / 7;
      check += newImage[0][0];
    newImage[0][j] = newImage[0][j] / 7;
      check += newImage[0][j];
     newImage[i][0] = newImage[i][0] / 7;
      check += newImage[i][0];
      newImage[i][cols-1] = newImage[i][j] / 7;
      check += newImage[i][j];
          

  return check;
   // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.
 

}


long mask(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
  return MASK_VERSION(oldImage, newImage, rows, cols);
}


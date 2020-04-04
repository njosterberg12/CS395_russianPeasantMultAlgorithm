/***************************************************************************************************************
 * Id: oste1799
 * Purpose:
 *  This program implements the Russian Peasant multiplication problem
 * Input:
 *  ./assignment13 # # where # are the integers to be multiplied
 * Output:
 *  The 2 numbers to be multiplied together are either halved or doubled, and then the product is printed
 *  on the bottom line
 * Compile:
 *  ex. gcc -Wall -o assignment13 assignment13.c
 ***************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void peasantMult(int, int);
void printMult(int, int, bool, int);
int main(int argc, char *argv[]){
   int leftVal;
   int rightVal;
   if(argc > 3)
   {
      printf("Too many args given. Should have 2 ints total\n");
      return 0;
   }
   if(argc < 3)
   {
      printf("Not enough args given. Should have 2 ints total.\n");
      return 0;
   }
   leftVal = atof(argv[1]);
   rightVal = atof(argv[2]);
   if (leftVal == 0 || rightVal == 0)
   {
      printf("Cannot multiply by 0");
      return 0;
   }
   peasantMult(leftVal, rightVal);
   return 0;
}
// fuction that does peasant multiplication
void peasantMult(int left, int right){
   int sum = 0;
   bool thirdCol = false;
   if(left % 2 == 1)
   {
      thirdCol = true;
      sum = sum + right;
      printMult(left, right, thirdCol, sum);
   }
   if(left % 2 == 0)
   {
      thirdCol = false;
      printMult(left, right, thirdCol, sum);
   }
   while(left > 1) // loop continues while left value > 1
   {
      right = right * 2;
      left = left / 2;
      if (left%2 == 1)
      {
         thirdCol = true; // thirdCol true when left Val is false.
         sum = sum + right; // when left col is odd, the right value is added to sum.
         printMult(left, right, thirdCol, sum);
      }
      if (left%2 == 0)
      {
         thirdCol = false; // ignore third column in print
         printMult(left, right, thirdCol, sum);
      }
   }
}
// this function prints the output of the multiplication
void printMult(int left, int right, bool thirdCol, int sum){
   if (thirdCol == true)
   {
      printf("%6d %6d %6d\n", left, right, right);
   }
   else
   {
      printf("%6d %6d\n", left, right);
   }
   if (left == 1)
   {
      printf("%20s\n", "------");
      printf("%20d\n", sum);
   }
}
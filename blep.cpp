#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<ctime>

using namespace std;
 struct Penis
      {
          string firstName;
          string lastName;
          char coursegrade;
          int testScore;
          int programmingScore;
          double GPA;
      };

  int main()
  {
      int r =3;
      int c= 3;

       int mat[3][3];
        for (int x = 0; x < r; x++) //Nested for loop for outputting the matrix
       for (int y = 0; y < c; y++) 
          cout << mat[x][y] << " \n"[y == c-1]; // Prints whitespace if j != n-1 else prints new line
          





  }                             
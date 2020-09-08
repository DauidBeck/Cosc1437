#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
//FINAL GRADE ON ASSIGNMENT : 100
using namespace std;

int main()

{
    srand(time(0));
    int uni = 0;
    const int iterate = 10000000;
    int ct = 0;
    const int r = 3, c = 3;
    int mat[r][c];
    for (int x = 0; x < iterate; x++)
    {
        /*mat[0][0] = 2;
      mat[0][1] = 7;
      mat[0][2] = 6;
      mat[1][0] = 9;  //DEBUG PLEASE IGNORE
      mat[1][1] = 5;
      mat[1][2] = 1;
      mat[2][0] = 4;
      mat[2][1] = 3;
      mat[2][2] = 8; */

        //Populate the matrix with random values from 1-10
        for (int x = 0; x < r; x++)
            for (int y = 0; y < c; y++)
            {
                mat[x][y] = rand() % 9 + 1;
                // cout<<mat[x][y]<<endl;
            }

        bool rows, columns, diagonals;
        int sum0R = 0, sum0C = 0, sum1R = 0, sum1C = 0, sum2R = 0, sum2C = 0, sumDiagL = 0, sumDiagR = 0;

        //take sum of row 0
        for (int x = 0; x < r; x++)
            sum0R += mat[0][x];

        //take sum of row 1
        for (int x = 0; x < r; x++)
            sum1R += mat[1][x];
        //take sum of row 2
        for (int x = 0; x < r; x++)
            sum2R += mat[2][x];

        int Row = sum0R + sum1R + sum2R;

        //take sum of column 0
        for (int y = 0; y < c; y++)
            sum0C += mat[y][0];

        //take sum of column 1
        for (int y = 0; y < c; y++)
            sum1C += mat[y][1];

        //take sum of column 2
        for (int y = 0; y < c; y++)
            sum2C += mat[y][2];

        int Col = sum0C + sum1C + sum2C;
        //take sum of diagonal right
        for (int x = 0; x < r; x++)
            sumDiagR += mat[x][x];

        //cout<<DiagSumR*r<<" <- Sum of right diagonal * number of columns/rows"<<endl;

        //take sum of diagonal left
        int count = c - 1;

        for (int x = 0; x < c; x++)
        {
            sumDiagL += mat[x][count];
            count--;
        }
        //cout<<DiagSumL*r<<" <- Diag Left sum * number of columns/rows"<<endl<<endl;

        //out<<sum0C<<endl;
        int together = 0;
        together = sum0C + sum1C + sum2C + sum0R + sum1R + sum2R + sumDiagL + sumDiagR;
        //cout<<together<<endl;
        //cout<<sum0C<<endl;

        //cout<<CSum <<endl; cout<< RSum <<endl; cout<< DiagSumL <<endl; cout<<  DiagSumR <<endl; cout<< sum1C <<endl; cout<< sum1R<<endl;
        //cout<<together<<endl;
        //final output of logic
        int sav[r][c];
        if (sum0C == sum0R && sum0R == sum1R && sum1R == sum2R && sum2R == sumDiagL && sum0C == sumDiagR && sumDiagR == sum0C && sum0C == sum1C && sum1C == sum2C)
        {

            uni++;
            cout << "Magic square with a sum of " << sum0C << " on each row, column, and diagonal." << endl;
            for (int x = 0; x < r; x++) //Nested for loop for outputting the matrix
                for (int y = 0; y < c; y++)
                    cout << mat[x][y] << " \n"[y == c - 1]; // Prints whitespace if j != n-1 else prints new line
        }

        //return 0;
    }
    cout << "there were " << uni << " Magic Squares out of " << iterate << " Cases" << endl;
}

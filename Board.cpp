#include <iostream>

using namespace std;

char** GameBoard();

char** Matrix = GameBoard();

char** GameBoard()
{
    char** Matrix;
    int row = 0;
    int column = 0;

    Matrix = new char* [45];

    for( int row = 0; row <= 44; row++ )
    {
        Matrix[row] = new char[89];
    }

    while( row <= 44 )
    {
        column = 0;
        while( column <= 88 )
        {
            if( row % 4 == 0 )
            {
                Matrix[row][column] = '*';
                Matrix[row][column+1] = ' ';
                column +=2 ;
            }

            else
            {
                if( column % 8 == 0 )
                {
                    Matrix[row][column] = '*';
                    column +=1 ;
                }

                else
                {
                    Matrix[row][column]  = ' ';
                    column +=1 ;
                }
            }
        }
        row += 1;
    }
    return( Matrix );
}


























#include <iostream>
#include <iomanip>
#include "Common.h"

using namespace std;



Board_Maker :: Board_Maker()
{
    //Game_Table

    int row = 0;
    int column = 0;

    Board = new char* [45];

    for( int row = 0; row <= 44; row++ )
    {
        Board[row] = new char[89];
    }

    while( row <= 44 )
    {
        column = 0;
        while( column <= 88 )
        {
            if( row == 22 && column == 41)
            {
                Board[row][column] = 'T';
                Board[row][column+1] = 'a';
                Board[row][column+2] = 'r';
                Board[row][column+3] = 'g';
                Board[row][column+4] = 'e';
                Board[row][column+5] = 't';
                Board[row][column+6] = '!';
                column += 7;
            }
            else if( row % 4 == 0 )
            {
                Board[row][column] = '*';
                Board[row][column+1] = ' ';
                column +=2 ;
            }

            else
            {
                if( column % 8 == 0 )
                {
                    Board[row][column] = '*';
                    column +=1 ;
                }

                else
                {
                    Board[row][column]  = ' ';
                    column +=1 ;
                }
            }
        }
        row += 1;
    }

    //Players_Table

    Players_Location = new int* [4];

    for( int index = 0; index < 4; index++ )
    {
        Players_Location[index] = new int[2];
    }
    Players_Location[0][0] = 2;
    Players_Location[0][1] = 4;
    Players_Location[1][0] = 2;
    Players_Location[1][1] = 84;
    Players_Location[2][0] = 42;
    Players_Location[2][1] = 4;
    Players_Location[3][0] = 42;
    Players_Location[3][1] = 84;
}


void Board_Maker :: Players_Movement( int PlayerNum, char Direction )
{
    if( Direction == 'w' )
    {
        Players_Location[PlayerNum-1][0] -= 1;
    }

    else if( Direction == 's' )
    {
        Players_Location[PlayerNum-1][0] += 1;
    }

    else if( Direction == 'd' )
    {
        Players_Location[PlayerNum-1][1] += 1;
    }

    else if( Direction == 'a' )
    {
        Players_Location[PlayerNum-1][1] -= 1;
    }

    else
    {
        cout << "Wrong Direction" << endl;
    }
}


void Board_Maker :: Set_Wall_On_Map( int x, int y, char status )
{
    if( status == 'H' )
    {
        Board[x-2][2*y-4] = 'W';
        Board[x-2][2*y-2] = 'W';
        Board[x-2][2*y]   = 'W';
        Board[x-2][2*y+2] = 'W';
        Board[x-2][2*y+4] = 'W';
    }

    else if( status == 'V' )
    {
        Board[x-2][2*y+4] = 'W';
        Board[x-1][2*y+4] = 'W';
        Board[x][2*y+4]   = 'W';
        Board[x+1][2*y+4] = 'W';
        Board[x+2][2*y+4] = 'W';
    }
}


void Board_Maker :: Board_View()
{
    system("clear");

    for( int row = 0; row < 45; row++ )
    {
        for( int column = 0; column < 89; column++ )
        {
            if( row == Players_Location[0][0] && column == Players_Location[0][1] )
            {
                cout << '1';
            }

            else if( row == Players_Location[1][0] && column == Players_Location[1][1] )
            {
                cout << '2';
            }

            else if( row == Players_Location[2][0] && column == Players_Location[2][1] )
            {
                cout << '3';
            }

            else if( row == Players_Location[3][0] && column == Players_Location[3][1] )
            {
                cout << '4';
            }  

            else
            {
                cout << Board[row][column];
            }  
        }
        cout << endl;
    }
    cout << endl;
    cout << "Current Is" << Current_Players_Number << endl;
}

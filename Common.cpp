#include <iostream>
#include <iomanip>
#include <string>
#include "Common.h"

using namespace std;


Board_Maker :: Board_Maker()
{

    //Players_Location_Table;

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

    //Players_Name

    Players_Name = new string*[4];

    for( int index = 0; index < 4; index++ )
    {
        Players_Name[index] = new string[1];
    }


    //Movement_Allowed

    Movement_Allowed = new bool*[4];

    for( int index = 0; index < 4; index++ )
    {
        Movement_Allowed[index] = new bool[1];
        
        if( index == 0 )
        {
            Movement_Allowed[index][0] = true;
        }

        else
        {
            Movement_Allowed[index][0] = false;
        }
    }
}


void Board_Maker :: Set_Players_On_Map( int PlayersNum )
{
    if( PlayersNum == 2 )
    {
        Board[Players_Location[0][0]][Players_Location[0][1]] = char(1);
        Board[Players_Location[1][0]][Players_Location[1][1]] = char(2);
    }

    else if( PlayersNum == 3 )
    {
        Board[Players_Location[0][0]][Players_Location[0][1]] = char(1);
        Board[Players_Location[1][0]][Players_Location[1][1]] = char(2);
        Board[Players_Location[2][0]][Players_Location[2][1]] = char(3);
    }

    else if( PlayersNum == 4 )
    {
        Board[Players_Location[0][0]][Players_Location[0][1]] = char(1);
        Board[Players_Location[1][0]][Players_Location[1][1]] = char(2);
        Board[Players_Location[2][0]][Players_Location[2][1]] = char(3);
        Board[Players_Location[3][0]][Players_Location[3][1]] = char(4);
    }
}


std :: string Board_Maker :: Can_Go_There( int PlayerNum, char Direction )
{
    if( Direction == 'w' )
    {
        if( Board[Players_Location[PlayerNum][0] - 2][Players_Location[PlayerNum][1]] == 'W' )
        {
            return( "You Cant Go There Because of The Wall");
        }

        if( Players_Location[PlayerNum][0] == 2 )
        {
            return("You Cant Go There You Should be In Board");
        }
    }
    
    else if( Direction == 's' )
    {
        if( Board[Players_Location[PlayerNum][0] + 2][Players_Location[PlayerNum][1]] == 'W' )
        {
            return( "You Cant Go There Because of The Wall");
        }

        if( Players_Location[PlayerNum][0] == 42  )
        {
            return("You Cant Go There You Should be In Board");
        }
    }

    else if( Direction == 'd' )
    {
        if( Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1] + 4] == 'W' )
        {
            return( "You Cant Go There Because of The Wall");
        }

        if( Players_Location[PlayerNum][1] == 84 )
        {
            return("You Cant Go There You Should be In Board");
        }
    }
    
    else if( Direction == 'a' )
    {
        if( Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1] - 4] == 'W' )
        {
            return( "You Cant Go There Because of The Wall");
        }

        if( Players_Location[PlayerNum][1] == 4 )
        {
            return("You Cant Go There You Should be In Board");
        }
    }
    return( "Allowed" );
}




void Board_Maker :: Players_Movement( int PlayerNum, char Direction )
{
    if( Direction == 'w' )
    {
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = ' ';
        Players_Location[PlayerNum][0] -= 4;
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = char(PlayerNum+1);
    }

    else if( Direction == 's' )
    {
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = ' ';
        Players_Location[PlayerNum][0] += 4;
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = char(PlayerNum+1);
    }

    else if( Direction == 'd' )
    {
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = ' ';
        Players_Location[PlayerNum][1] += 8;
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = char(PlayerNum+1);
    }

    else if( Direction == 'a' )
    {
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = ' ';
        Players_Location[PlayerNum][1] -= 8;
        Board[Players_Location[PlayerNum][0]][Players_Location[PlayerNum][1]] = char(PlayerNum+1);
    }

    else
    {
        cout << "Wrong Direction" << endl;
    }
}


void Board_Maker :: Set_Wall_On_Map( int wallnumber, string status )
{
    if( status == "Horizontal" )
    {
        int row;
        int column;
        row = (( wallnumber - 1 ) / 11 ) * 4;
        column = ( wallnumber % 11 ) * 8;

        Board[row][column]   = 'W';
        Board[row][column-2] = 'W';
        Board[row][column-4] = 'W';
        Board[row][column-6] = 'W';
        Board[row][column-8] = 'W';
    }

    else if( status == "Vertical" )
    {
        int row;
        int column;
        row = (( wallnumber - 1) / 12) * 4;

        if( wallnumber % 12 == 0 )
        {
            column = 88;
        }

        else
        {
            column = ( wallnumber % 12 - 1 ) * 8;
        }
        
        Board[row][column]   = 'W';
        Board[row+1][column] = 'W';
        Board[row+2][column] = 'W';
        Board[row+3][column] = 'W';
        Board[row+4][column] = 'W';
    }
}


void Board_Maker :: Board_View( int playersnumber )
{
    for( int row = 0; row < 45; row++ )
    {
        for( int column = 0; column < 89; column++ )
        {
            cout << Board[row][column];
        }
        cout << endl;
    }
    cout << endl;
}

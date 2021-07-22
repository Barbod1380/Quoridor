#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include "Board.cpp"

using namespace std;


class Board
{
    public:
        
        Board( bool );

        void View();
        void Input();
        void Logic();
        void In_Board_Check();
        void Game_Check();

        bool GameOver;
        bool Out_Of_Board;


    private:

        enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
        Direction dir;

        int x;
        int y;
};


Board :: Board( bool X )
    : x( 2 ), y( 2 )
{
    GameOver = false;
    Out_Of_Board = false;
}

void Board :: View()
{
    system( "clear" );

    for( int row = 0; row < 45; row++ )
    {
        for( int column = 0; column < 89; column++ )
        {
            if( row != x || column != 2*y)
            {
                cout << Matrix[row][column];
            }

            else
            {
                cout << 'M';
            }
        }
        cout << endl;
    }
}


void Board :: Input()
{
    char Movement;

    while( true )
    {
        cin >> Movement;

        if( Movement == 'w' )
        {
            dir = UP;
            break;
        }

        else if( Movement == 'a' )
        {
            dir = LEFT;
            break;
        }  

        else if( Movement == 'd' )
        {
            dir = RIGHT;
            break;
        }

        else if( Movement == 's')
        {
            dir = DOWN;
            break;
        }

        else
        {
            cout << "Incorrect Input" << endl;
        }
    }
}


void Board :: Logic()
{
    if( dir == UP )
    {
        x -= 4;
    }

    else if( dir == LEFT )
    {
        y -= 4;
    }

    else if( dir == RIGHT )
    {
        y += 4;
    }

    else if( dir == DOWN )
    {
        x += 4;
    }
}


void Board :: In_Board_Check()
{
    if( x == 2 && dir == UP )
    {
        Out_Of_Board = true;
    }

    else if( x == 42 && dir == DOWN )
    {
        Out_Of_Board = true;
    }

    else if(  y == 2 && dir == LEFT )
    {
        Out_Of_Board = true;
    }

    else if( y == 42 && dir == RIGHT )
    {
        Out_Of_Board = true;
    }

    else
    {
        Out_Of_Board = false;
    }
}


void Board :: Game_Check()
{
    if( x == 22 && y == 22 )
    {
        GameOver = true;
    }
}


int main()
{
    Board board( true );

    while( !(board.GameOver) )
    {
        board.View();
        board.Input();
        board.In_Board_Check();

        if( board.Out_Of_Board == false )
        {
            board.Logic();
            board.Game_Check();       
        }

        else
        {
            cout << "You Cant Go That Way You Getting Out Of The Board !" << endl;
        }

        sleep(2);
    }

    board.View();
}
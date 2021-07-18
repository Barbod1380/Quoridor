#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>

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
        if( row % 4 == 0 )
        {
            for( int column = 0; column < 45; column++ )
            {
                cout << '*' << " ";
            }
            cout << endl;
        }

        else
        {
            for( int column = 0; column <= 88; column++ )
            {
                if( column % 8 == 0 )
                {
                    cout << '*';
                }
                else
                {
                    if( row == x && column == 2*y )
                    {
                        cout << 'M';
                    }

                    else
                    {
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
    }
}



void Board :: Input()
{
    switch( getchar() )
    {
        case 'w':
        {
            dir = UP;
            break;
        }

        case 'a':
        {
            dir = LEFT;
            break;
        }

        case 'd':
        {
            dir = RIGHT;
            break;
        }

        case 's':
        {
            dir = DOWN;
            break;
        }
    }
}


void Board :: Logic()
{
    switch( dir )
    {
        case UP:
        {
            x -= 2;
            break;
        }

        case LEFT:
        {
            y -= 2;
            break;
        }

        case RIGHT:
        {
            y += 2;
            break;
        }

        case DOWN:
        {
            x += 2;
            break;
        }
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

























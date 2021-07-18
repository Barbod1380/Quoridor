#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;


enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
Direction dir;

bool GameOver;
int x;
int y;


void Setup()
{
    GameOver = false;
    x = 2;
    y = 2;
}


void view()
{
    cout << endl;

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


void Input()
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


void Logic()
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


void GameCheck()
{
    if( x == 22 && y == 22 )
    {
        GameOver = true;
    }
}

int main()
{
    Setup();

    while( !GameOver )
    {
        view();
        Input();
        Logic();
        GameCheck();
    }
}

























#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;


enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
Direction dir;

bool GameOver;
int x = 2;
int y = 2;


void Setup()
{
    GameOver = false;
    x = 2;
    y = 2;
}


void view()
{
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
            cout << "X IS  " << x << endl;
            break;
        }

        case LEFT:
        {
            y -= 2;
            cout << "Y IS  " << y << endl;
            break;
        }

        case RIGHT:
        {
            y += 2;
            cout << "Y IS  " << y << endl;
            break;
        }

        case DOWN:
        {
            cout << "X Before Is  " << x << endl;
            x += 2;
            cout << "X After IS  " << x << endl;
            break;
        }
    }
}


int main()
{
    for( int counter = 0; counter < 8; counter++ )
    {
        view();
        Input();
        Logic();
    }
}
























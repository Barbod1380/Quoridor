#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>

using namespace std;


class Wall
{
    public:
        
        Wall();

        void Choose_Wall_Type();
        void Choose_Wall_Coordinate();
        void Set_Wall( int, int );
        void Logic();

        string Wall_Status;
        int x;
        int y;

    private:
        enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
        Direction dir;

};

Wall :: Wall()
{
    x = 1;
    y = 1;
}


void Wall :: Choose_Wall_Type()
{
    cout << "What Type Of Wall Do You Want? (Inter h for Horizontal And Inter v for Vertical)" << endl;

    cout << "h)" << endl;
    cout << "# # # # #" << endl;

    cout << "v)" << endl;
    for( int counter = 0; counter < 5; counter++ )
    {
        cout << '#' << endl;
    }

    switch ( getchar() )
    {
        case 'v':
        {
            Wall_Status = "Vertical";
            break;
        }

        case 'h':
        {
            Wall_Status = "Horizontal";
            break;
        }
    }
}


void Wall :: Choose_Wall_Coordinate()
{
    switch ( getchar() )
    {
        case 'w':
            dir = UP;
            break;
        
        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 's':
            dir = DOWN;
            break;
    }
}


void Wall :: Logic()
{
    switch( dir )
    {
        case UP:
        {
            x -= 1;
            break;
        }

        case LEFT:
        {
            y -= 1;
            break;
        }

        case RIGHT:
        {
            y += 1;
            break;
        }

        case DOWN:
        {
            x += 1;
            break;
        }
    }
}



void Wall :: Set_Wall( int Row, int Column )
{
    if( Row > 10 || Row < 1 )
    {
        cout << "Row Coordinate Is Wrong" << endl;
    }

    else if( Column > 10 || Column < 1 )
    {
        cout << "Column Coordinate Is Wrong" << endl;
    }

    else
    {

    }
}













#include <iostream>
#include <iomanip>
#include "Board.cpp"

using namespace std;


class Wall
{
    public:
        
        Wall( bool );

        void Choose_Wall_Coordinate();
        void Choose_Wall_Type();
        void Set_Wall_On_Map();
        void View_Horizontal();
        void In_Board_Check();
        void View_Vertical();
        void Set_Wall();
        void Logic();

        string Wall_Status;
        bool Inside_Board = true;

    private:

        int x;
        int y;
        enum Direction { UP, DOWN, LEFT, RIGHT, SET };
        Direction dir;
};


Wall :: Wall( bool Status )
    : x(2), y(2)
{
}


void Wall :: Choose_Wall_Type()
{
    cout << "What Type Of Wall Do You Want? (Inter h for Horizontal And Inter v for Vertical)" << endl;

    cout << "h)" << endl;
    cout << "v)" << endl;

    char Wall_Type;

    while( true )
    {
        cin >> Wall_Type;

        if( Wall_Type == 'v' )
        {
            Wall_Status = "Vertical";
            break;
        }

        else if( Wall_Type == 'h' )
        {
            Wall_Status = "Horizontal";
            break;
        }

        else
        {
            cout << "Incorrect Input" << endl;
        }
    }
}


void Wall :: Choose_Wall_Coordinate()
{
    char Position;

    while( true )
    {
        cin >> Position;

        if( Position == 'w' )
        {
            dir = UP;
            break;
        }

        else if( Position == 'a' )
        { 
            dir = LEFT;
            break;
        } 

        else if( Position == 'd' )
        {
            dir = RIGHT;
            break;
        }

        else if( Position == 's' )
        {
            dir = DOWN;
            break;
        }

        else if( Position == 'p' )
        {
            dir = SET;
            break;
         }

        else
        {
            cout << "Incorrect Input" << endl;
        }
    }
}


void Wall :: Logic()
{
    switch( dir )
    {
        case UP:
        {
            x -= 4;
            break;
        }

        case LEFT:
        {
            y -= 4;
            break;
        }

        case RIGHT:
        {
            y += 4;
            break;
        }

        case DOWN:
        {
            x += 4;
            break;
        }

        case SET:
        {
            Set_Wall_On_Map() ;  
            break;
        }

        default:
            break;
    }
}


void Wall :: Set_Wall_On_Map()
{
    if( Wall_Status == "Horizontal" )
    {
        Matrix[x-2][2*y-4] = 'W';
        Matrix[x-2][2*y-2] = 'W';
        Matrix[x-2][2*y]   = 'W';
        Matrix[x-2][2*y+2] = 'W';
        Matrix[x-2][2*y+4] = 'W';
    }

    else if( Wall_Status == "Vertical" )
    {
        Matrix[x-2][2*y+4] = 'W';
        Matrix[x-1][2*y+4] = 'W';
        Matrix[x][2*y+4]   = 'W';
        Matrix[x+1][2*y+4] = 'W';
        Matrix[x+2][2*y+4] = 'W';
    }
}


void Wall :: View_Vertical()
{  
    for( int row = 0; row < 45; row++ )
    {
        for( int column = 0; column < 89; column++ )
        {
            if( row != x || column != 2*y + 3 )
            {
                cout << Matrix[row][column];
            }

            else
            {
                cout << '>';
            }
        }
        cout << endl;
    }
}


void Wall :: View_Horizontal()
{
    for( int row = 0; row < 45; row++ )
    {
        for( int column = 0; column < 89; column++ )
        {
            if( row != x - 1 || column != 2*y )
            {
                cout << Matrix[row][column];
            }

            else
            {
                cout << '^';
            }
        }
        cout << endl;
    }
}


void Wall :: In_Board_Check()
{
    if( x == 2 && dir == UP )
    {
        Inside_Board = false;
    }

    else if( x == 42 && dir == DOWN )
    {
        Inside_Board = false;
    }

    else if( y == 2 && dir == LEFT )
    {
        Inside_Board = false;
    }

    else if( y == 42 && dir == RIGHT )
    {
        Inside_Board = false;
    }

    else
    {
        Inside_Board = true;
    }
}



int main()
{
    Wall wall( true );

    while( true )
    {
        wall.Choose_Wall_Type();

        if( wall.Wall_Status == "Horizontal" )
        {
            while( true )
            {
                wall.View_Horizontal();
                wall.Choose_Wall_Coordinate();
                wall.In_Board_Check();

                if( wall.Inside_Board == true )
                {
                    wall.Logic();
                }

                else
                {
                    cout << "You Are Getting Out Of The Board" << endl;
                }
            }
        }

        else if( wall.Wall_Status == "Vertical" )
        {
            while( true )
            {
                wall.View_Vertical();
                wall.Choose_Wall_Coordinate();
                wall.In_Board_Check();

                if( wall.Inside_Board == true )
                {
                    wall.Logic();
                }

                else
                {
                    cout << "You Are Getting Out Of The Board" << endl;
                }
            }   
        }
    }
   char** M = GameBoard();
}












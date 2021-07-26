#include "httplib.h"
#include "Common.cpp"

using namespace std;


class Move
{
    public:
        
        Move();
        char Select_Movement_Direction();
        void Choose_Wall_Type();
        void Set_Wall();
        void Logic();
        void Set_Wall_On_Map( char** & );
        void View_Vertical( char** );
        void View_Horizontal( char** );
        bool In_Board_Check();


        string Wall_Status;
        bool Set = false;
        char Position;
        int x;
        int y;


    private:

};

Move :: Move()
{
    x = 2;
    y = 2;
}


char Move :: Select_Movement_Direction()
{
    char Direction;
    cout << "Inter Your Direction (w for Up, s for Down, d for Right, a for Left)" << endl;
    cin >> Direction;

    while( Direction != 'w' && Direction != 's' && Direction != 'd' && Direction != 'a' )
    {
        cout << "Incorrect Input" << endl;
        cin >> Direction;
    }
    return( Direction ); 
}


void Move :: Choose_Wall_Type()
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


void Move :: Set_Wall()
{
    while( true )
    {
        cin >> Position;

        if( Position == 'w' )
        {
            x -= 4;
            break;
        }

        else if( Position == 'a' )
        { 
            y -= 4;
            break;
        } 

        else if( Position == 'd' )
        {
            y += 4;
            break;
        }

        else if( Position == 's' )
        {
            x += 4;
            break;
        }

        else if( Position == 'p' )
        {
            Set = true;
            break;
         }

        else
        {
            cout << "Incorrect Input" << endl;
        }
    }
}


void Move :: View_Horizontal( char** Matrix )
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


void Move :: View_Vertical( char** Matrix )
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


bool Move :: In_Board_Check()
{
    if( x == -2 && Position == 'w' )
    {
        x += 4;
        return false;
    }

    else if( x == 46 && Position == 's' )
    {
        x -= 4;
        return false;
    }

    else if( y == -2 && Position ==  'a' )
    {
        y += 4;
        return false;
    }

    else if( y == 46 && Position == 'd' )
    {
        y -= 4;
        return false;
    }

    else
    {
        return true;
    }
}



int main()
{
    string username;

    char Direction;
    int Choice;
    httplib::Client cli("localhost", 8080);

    Move move;
    Board_Maker Bmaker;

    cout << "Inter Your Username" << endl;
    cin >> username;


    if( auto res = cli.Get("/join") )
    {
        if( res -> status == 200 )
        {
            cout << res -> body << " " << username << endl;
            Bmaker.Board_View();
            cout << endl;
        }
    }

    cout << "Wall Or Move? (Inter 1 for Move and 2 for Wall) " << endl;
    cout << "1) Wall" << endl;
    cout << "2) Move" << endl;

    cin >> Choice;


    while( Choice != 1 && Choice != 2 )
    {
        cout << "Incorrect Input" << endl;
        cin >> Choice;
    }


    if( Choice == 1 )
    {
        move.Choose_Wall_Type();

        if( move.Wall_Status == "Vertical" )
        {
            while( true )
            {
                move.Set = false;
                move.View_Vertical( Bmaker.Board );
                move.Set_Wall();
                bool status = move.In_Board_Check();

                if( move.Set == true )
                {
                    Bmaker.Set_Wall_On_Map( move.x, move.y, 'V' );
                    Bmaker.Board_View();
                    move.Set = false;
                    break;
                }
            }
        }

        else if( move.Wall_Status == "Horizontal" )
        {
            while( true )
            {
                move.Set = false;
                move.View_Horizontal( Bmaker.Board );
                move.Set_Wall();
                bool status = move.In_Board_Check();

                if( move.Set == true )
                {
                    Bmaker.Set_Wall_On_Map( move.x, move.y, 'H' );
                    Bmaker.Board_View();
                    move.Set = false;
                    break;
                }
            }
        }
    }


    else if( Choice ==  2 )
    {
        Direction = move.Select_Movement_Direction();

        if( Direction == 'w' )
        {
            auto res = cli.Get("/Move_Up");

            if( res -> status == 200 )
            {
                cout << res -> body << endl;
            }
        }


        else if( Direction == 's' )
        {
            auto res = cli.Get("/Move_Down");

            if( res -> status == 200 )
            {
                cout << res -> body << endl;
            }
        }


        else if( Direction == 'd' )
        {
            auto res = cli.Get("/Move_Right");

            if( res -> status == 200 )
            {
                cout << res -> body << endl;
            }
        }


        else if( Direction == 'a')
        {
            auto res = cli.Get("/Move_Left");

            if( res -> status == 200 )
            {
                cout << res -> body << endl;
            }
        }
    }
}
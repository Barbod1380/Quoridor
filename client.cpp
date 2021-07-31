#include <iostream>
#include <string>
#include "httplib.h"
#include "Common.h"

using namespace std;

class Move
{
    public:
        
        Move();
        char Select_Movement_Direction();
        void Choose_Wall_Type();
        void Set_Wall();
        void Logic();
        void Open_Map( string );
        void Set_Wall_On_Map( char** & );
        string Choose_Vertical_Wall_Number();
        string Choose_Horizontal_Wall_Number();

        int  Open_Pass( string );
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


string Move :: Choose_Vertical_Wall_Number()
{
    int Wall_Number;

    cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "  1*      2*      3*      4*      5*      6*      7*      8*      9*     10*     11*     12*" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl; 
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " 13*     14*     15*     16*     17*     18*     19*     20*     21*     22*     23*     24*" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "                                           ." << endl;
    cout << "                                           ." << endl;
    cout << "                                           ." << endl;
    cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "109*    110*     111*   112*    113*    114*    115*    116*    117*    118*    119*    120*" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "121*    122*    123*    124*    125*    126*    127*    128*    129*    130*    131*    132*" << endl;
    cout << "   *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << "   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;

    cout << "Inter Wall Number" << endl;
    cin >> Wall_Number;
    return( to_string(Wall_Number) );
}


string Move :: Choose_Horizontal_Wall_Number()
{
    int Wall_Number;

    cout << "     1       2       3       4       6       6       7       8       9       10      11   " << endl;
    cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << " *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " *  12   *   13  *   14  *   15  *   16  *   17  *   18  *   19  *  20   *   21  *   22  *" << endl;
    cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << " *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " *  23   *  24   *   25  *   26  *   27  *   28  *   29  *   30  *  31   *   32  *   33  *" << endl;
    cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "                                         ." << endl;
    cout << "                                         ." << endl;
    cout << "                                         ." << endl;
    cout << "    111     112     113     114     115     116     117     118     119     120     121   " << endl;
    cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << " *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " *       *       *       *       *       *       *       *       *       *       *       *" << endl;
    cout << " *  122  *  123  *  124  *  125  *  126  *  127  *  128  *  129  *  130  *  131  *  132  *" << endl;
    cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;

    cout << "Inter Wall Number" << endl;
    cin >> Wall_Number;
    return( to_string(Wall_Number) );
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


void Move :: Open_Map( string board )
{
    for( int row = 0; row < 45; row++ )
    {
        for( int column = 0; column < 89; column++ )
        {
            cout << board[(row*89) + column];
        }
        cout << endl;
    }
    cout << endl;
}


int Move :: Open_Pass( string password )
{
    int passint;
    passint = stoi( password );
    return( passint );
}



int main()
{
    int Players_Number;
    int Current_Players_Number;
    char Direction;
    char Choice;
    string username;

    httplib::Client cli("localhost", 8080);

    Move move;

    cout << "Inter Your Username" << endl;
    cin >> username;


    httplib :: MultipartFormDataItems items = {
        { "username", username } ,
    };


    if( auto res = cli.Post("/join", items) )
    {
        if( res -> status == 200 && res -> body == "You Cant Join The Game" )
        {
            cout << res -> body << endl;
            exit(1);
        }

        else if( res -> status == 200 )
        {
            int OpenPass;
            cout << "You Join The Game Succesfully" << endl;

            OpenPass = move.Open_Pass( res -> body );
 
            Players_Number = OpenPass / 10;
            Current_Players_Number = OpenPass % 10;

            cout << "Your Number Is: " << Current_Players_Number << endl;
        }
    }


    while( Current_Players_Number < Players_Number )
    {
        sleep(7);
        cout << "Wait For Other Players" << endl;

        if( auto res = cli.Get( "/Status" ) )
        {
            if( res -> status == 200 )
            {
                int OpenPass;
                OpenPass = move.Open_Pass( res -> body );
                Players_Number = OpenPass / 10;
                Current_Players_Number = OpenPass % 10;
                cout << "Current Players Number Is " << Current_Players_Number << endl;
            }
        }
    }


    if( Current_Players_Number == Players_Number )
    {
        auto new_res = cli.Get( "/ViewBoard" );
        move.Open_Map( new_res -> body );
        
        while( Current_Players_Number == Players_Number )
        {
            auto res0 = cli.Post( "/WinnerCheck", items );

            if( res0 -> status == 200 )
            {
                if( res0 -> body != "there is no winner yet" )
                {
                    auto mapres = cli.Get( "/ViewBoard" );
                    if( mapres -> status == 200 )
                    {
                        move.Open_Map( mapres -> body );
                        cout << res0 -> body << endl;
                        exit(1);
                    }
                }
            }
        
            auto res = cli.Post( "/move", items );

            if( res -> status == 200 )
            {
                if( res -> body == "yes" )
                {
                    auto new_res = cli.Get( "/ViewBoard" );
                    move.Open_Map( new_res -> body );
                    cout << "Wall Or Move? (Inter 1 for Wall and 2 for Move) " << endl;
                    cout << "1) Wall" << endl;
                    cout << "2) Move" << endl;
                    cin >> Choice;

                    while( Choice != '1' && Choice != '2' )
                    {
                        cout << "Incorrect Input" << endl;
                        cin >> Choice;
                    }

                    if( Choice == '1' )
                    {
                        move.Choose_Wall_Type();

                        if( move.Wall_Status == "Vertical" )
                        {
                            string wallnumber;
                            wallnumber = move.Choose_Vertical_Wall_Number();

                            httplib::MultipartFormDataItems items1 = 
                            {
                                { "WallNumber", wallnumber },
                                { "WallStatus", "Vertical" }
                            };
                            
                            cli.Post( "/Set_Wall_On_Map", items1 );
                            auto res = cli.Get( "/ViewBoard" );
                            move.Open_Map( res -> body );
                            cli.Post( "/Change", items );
                        }

                        else if( move.Wall_Status == "Horizontal" )
                        {
                            string wallnumber;
                            wallnumber = move.Choose_Horizontal_Wall_Number();

                            httplib::MultipartFormDataItems items2 = {
                                { "WallNumber", wallnumber   },
                                { "WallStatus", "Horizontal" }
                            };

                            cli.Post( "/Set_Wall_On_Map", items2 );
                            auto res = cli.Get( "/ViewBoard" );
                            move.Open_Map( res -> body );
                            cli.Post( "/Change", items );
                        }
                    }

                    else if( Choice ==  '2' )
                    {
                        bool flag = true;

                        while( flag == true )
                        {
                            Direction = move.Select_Movement_Direction();

                            if( Direction == 'w' )
                            {
                                auto res = cli.Post("/Move_Up", items);

                                if( res -> status == 200 && res -> body != "Error" )
                                {
                                    cout << res -> body << endl;
                                    flag = false;
                                }
                                else
                                {
                                    cout << res -> body << endl;
                                }
                            }

                            else if( Direction == 's' )
                            {
                                auto res = cli.Post("/Move_Down", items);

                                if( res -> status == 200 && res -> body != "Error" )
                                {
                                    cout << res -> body << endl;
                                    flag = false;
                                }
                                else
                                {
                                    cout << res -> body << endl;
                                }
                            }

                            else if( Direction == 'd' )
                            {
                                auto res = cli.Post("/Move_Right", items);

                                if( res -> status == 200 && res -> body != "Error" )
                                {
                                    cout << res -> body << endl;
                                    flag = false;
                                }
                                else
                                {
                                    cout << res -> body << endl;
                                }
                            }

                            else if( Direction == 'a')
                            {
                                auto res = cli.Post("/Move_Left", items);

                                if( res -> status == 200 && res -> body != "Error" )
                                {
                                    cout << res -> body << endl;
                                    flag = false;
                                }
                                else
                                {
                                    cout << res -> body << endl;
                                }
                            }
                        }

                        auto res = cli.Get( "/ViewBoard" );
                        move.Open_Map( res -> body );

                        auto res0 = cli.Post( "/WinnerCheck", items );

                        if( res0 -> status == 200 )
                        {
                            if( res0 -> body != "there is no winner yet" )
                            {
                                cout << res0 -> body << endl;
                                exit(1);
                            }
                        }
                    }
                }

                else if( res -> body == "no" )
                {
                    cout << "You Are Not Allowed To Move" << endl;
                    sleep(8);
                }
            }

            else
            {
                cout << res.error() << endl; 
            }
        }
        auto newres = cli.Get( "/ViewBoard" );
        move.Open_Map( newres -> body );
    }
} 


























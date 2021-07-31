#include "httplib.h"
#include <iostream>
#include <string>
#include "Common.cpp"
 
using namespace std;
using namespace httplib;


class Board_Changes
{
    public:
        
        Board_Changes();

        bool Winner = false;
        string Winner_Username;
        int Players_Number;
        int Current_Players_Number; 

        void Make_Board();
        string MakePass( int, int );

    private:       
};


Board_Changes :: Board_Changes()
{   
}


string Board_Changes :: MakePass( int PlayersNum, int Current_Players_Numb )
{
    int Answer = PlayersNum*10 + Current_Players_Numb;
    string FinalAnswer = to_string( Answer );

    return( FinalAnswer );
}



int main(void)
{
    Server srv;

    Board_Maker boardmaker;
    Board_Changes boardchanges;

    cout << "Input Number Of Players" << endl;
    cin >> boardchanges.Players_Number;

    while( boardchanges.Players_Number > 4 || boardchanges.Players_Number < 2 )
    {
        cout << "Players Number should Be 2, 3 or 4" << endl;
        cin >> boardchanges.Players_Number;
    }

    boardmaker.Set_Players_On_Map( boardchanges.Players_Number );
    

    srv.Post("/join", [&](const auto& req, auto& res)
    {
        if( boardchanges.Current_Players_Number >= boardchanges.Players_Number )
        {
            res.set_content( "You Cant Join The Game", "text/plain" );
        }

        else
        {
            int index = 0;
            string new_response;

            while( boardmaker.Players_Name[index][0].size() != 0 && boardchanges.Current_Players_Number < boardchanges.Players_Number )
            {
                index++;
            }

            const auto& file = req.get_file_value( "username" );
            boardmaker.Players_Name[index][0] = file.content;
            boardchanges.Current_Players_Number += 1;
            cout << file.content << " Join The Game" << endl;

            new_response = boardchanges.MakePass( boardchanges.Players_Number, boardchanges.Current_Players_Number );
            res.set_content( new_response, "text/plain" );
        }
    });


    srv.Post("/move", [&](const auto& req, auto& res)
    {
        string PlayerName;

        const auto& file = req.get_file_value( "username" );
        PlayerName = file.content;
        
        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == PlayerName )
            {
                if( boardmaker.Movement_Allowed[index][0] == true )
                {
                    res.set_content( "yes", "text/plain" );
                }
                
                else
                {
                    res.set_content( "no", "text/plain" );
                }
            }
        }
    });


    srv.Get( "/Status", [&](const Request& req, Response& res)
    {
        string new_response;
        new_response = boardchanges.MakePass( boardchanges.Players_Number, boardchanges.Current_Players_Number );
        res.set_content( new_response, "text/plain" );
    });



    srv.Post("/Move_Up", [&](const Request& req, Response& res)
    {
        string PlayerName;
        string Status;

        const auto& file = req.get_file_value( "username" );
        PlayerName = file.content;

        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == PlayerName )
            {
                if( boardmaker.Movement_Allowed[index][0] == true )
                {
                    Status = boardmaker.Can_Go_There( index, 'w' );

                    if( Status == "Allowed" )
                    {
                        boardmaker.Players_Movement( index, 'w' );   
                        boardmaker.Movement_Allowed[index][0] = false;
                        boardmaker.Movement_Allowed[(index+1) % boardchanges.Current_Players_Number ][0] = true;
                        res.set_content( "You Move Up Succesfully", "text/plain" );
                    }

                    else
                    {
                        res.set_content( "Error", "text/plain" );
                    }
                }
            }
        }   
    });     
    

    srv.Post("/Move_Down", [&](const Request& req, Response& res)
    {
        string PlayerName;
        string Status;

        const auto& file = req.get_file_value( "username" );
        PlayerName = file.content;

        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == PlayerName )
            {
                if( boardmaker.Movement_Allowed[index][0] == true )
                {
                    Status = boardmaker.Can_Go_There( index, 's' );

                    if( Status == "Allowed" )
                    {
                        boardmaker.Players_Movement( index, 's' );   
                        boardmaker.Movement_Allowed[index][0] = false;
                        boardmaker.Movement_Allowed[(index+1) % boardchanges.Current_Players_Number ][0] = true;
                    }   

                    else
                    {
                        res.set_content( "Error", "text/plain" );
                    }
                }
            }
        } 
    });     
    

    srv.Post("/Move_Left", [&](const Request& req, Response& res)
    {
        string PlayerName;
        string Status;

        const auto& file = req.get_file_value( "username" );
        PlayerName = file.content;

        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == PlayerName )
            {
                if( boardmaker.Movement_Allowed[index][0] == true )
                {
                    Status = boardmaker.Can_Go_There( index, 'a' );

                    if( Status == "Allowed" )
                    {
                        boardmaker.Players_Movement( index, 'a' );   
                        boardmaker.Movement_Allowed[index][0] = false;
                        boardmaker.Movement_Allowed[(index+1) % boardchanges.Current_Players_Number ][0] = true;
                    }

                    else
                    {
                        res.set_content( "Error", "text/plain" );
                    }
                }
            }
        }
    }); 


    srv.Post("/Move_Right", [&](const Request& req, Response& res)
    {
        string PlayerName;
        string Status;

        const auto& file = req.get_file_value( "username" );
        PlayerName = file.content;

        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == PlayerName )
            {
                if( boardmaker.Movement_Allowed[index][0] == true )
                {
                    Status = boardmaker.Can_Go_There( index, 'd' );
                    
                    if( Status == "Allowed" )
                    {
                        boardmaker.Players_Movement( index, 'd' );   
                        boardmaker.Movement_Allowed[index][0] = false;
                        boardmaker.Movement_Allowed[(index+1) % boardchanges.Current_Players_Number ][0] = true;
                    }

                    else
                    {
                        res.set_content( "Error", "text/plain" );
                    }
                }
            }
        }
    }); 


    srv.Post("/Change", [&](const Request& req, Response& res)
    {
        string PlayerName;

        const auto& file = req.get_file_value( "username" );
        PlayerName = file.content;

        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == PlayerName )
            {
                if( boardmaker.Movement_Allowed[index][0] == true )
                {
                    boardmaker.Movement_Allowed[index][0] = false;
                    boardmaker.Movement_Allowed[(index+1) % boardchanges.Current_Players_Number ][0] = true;
                }
            }
        }
    });


    srv.Post("/Set_Wall_On_Map", [&](const Request& req, Response& res)
    {
        int WallNumber;
        string Wall_Status;

        const auto& file = req.get_file_value( "WallNumber" );
        WallNumber = stoi( file.content );

        const auto& file2 = req.get_file_value( "WallStatus" );
        Wall_Status = file2.content;

        boardmaker.Set_Wall_On_Map( WallNumber, Wall_Status );
    });


    srv.Get("/ViewBoard", [&](const Request& req, Response& res )
    {
        string GameBoard = "";

        for( int row = 0; row < 45; row++ )
        {
            for( int column = 0; column < 89; column++ )
            {
                GameBoard += boardmaker.Board[row][column];
            }
        }
        res.set_content( GameBoard, "text/plain" );
    });


    srv.Post("/WinnerCheck", [&](const Request& req, Response& res)
    {
        string username;

        const auto& file = req.get_file_value( "username" );
        username = file.content;

        for( int index = 0; index < 4; index++ )
        {
            if( boardmaker.Players_Name[index][0] == username )
            {
                if( boardmaker.Players_Location[index][0] == 22 && boardmaker.Players_Location[index][1] == 44 )
                {
                    boardchanges.Winner = true;
                    boardchanges.Winner_Username = boardmaker.Players_Name[index][0];
                }
            }   
        }

        if( boardchanges.Winner == true && boardchanges.Winner_Username == username )
        {
            res.set_content( "!!  Congratulations You Win The Game  !!", "text/plain" );
        }

        else if( boardchanges.Winner == true && boardchanges.Winner_Username != username )
        {
            res.set_content( "!!  Sorry But You Lose The Game  !!", "text/plain" ); 
        }

        else
        {
            res.set_content( "there is no winner yet", "text/plain" );
        }
    });

    srv.listen("localhost", 8080);
}



















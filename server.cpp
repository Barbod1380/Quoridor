#include <httplib.h>
#include <iostream>
#include "Common.h"
 
using namespace std;
using namespace httplib;

extern int Current_Players_Number;
extern int Players_Number;

class Board_Changes
{
    public:
        
        Board_Changes();

        char** Board;
        int**  Players_Location;

        void Make_Board();
        void Set_Players_Location();


    private:
        
};


Board_Changes :: Board_Changes()
{   
}


void Board_Changes :: Set_Players_Location()
{
    Players_Location = new int* [4];

    for( int index = 0; index < 4; index++ )
    {
        Players_Location[index] = new int[2];
    }

    for( int Row = 0; Row < 4; Row++ )
    {
        for( int Column = 0; Column < 2; Column++ )
        {
            if( ( Row == 0 && Column == 0 ) || ( Row == 0 && Column == 1 ) || ( Row == 1 && Column == 0 ) || ( Row == 2 && Column == 1) )
            {
                Players_Location[Row][Column] = 0;
            }
            else
            {
                Players_Location[Row][Column] = 10;
            }
        }
    }
}



int main(void)
{
    Server srv;

    cout << "Inter The Number Of Player" << endl;
    cin >> Players_Number;
    
    srv.Get("/join", [](const Request& req, Response& res)
    { 
        cout << "New Player Join The Game" << endl;
        Current_Players_Number ++;
        cout << "Current Player Number Is:  " << Current_Players_Number << endl;
        res.set_content("Welcome", "text/plain");
    }); 


    srv.Get("/Move_Up", [](const Request& req, Response& res)
    {
        res.set_content("You Move Up Succesfully", "text/plain");
    });     
    

    srv.Get("/Move_Down", [](const Request& req, Response& res)
    {
        res.set_content("You Move Down Succesfully", "text/plain");
    });     
    

    srv.Get("/Move_Left", [](const Request& req, Response& res)
    {
        res.set_content("You Move Left Succesfully", "text/plain");
    }); 


    srv.Get("/Move_Right", [](const Request& req, Response& res)
    {
        res.set_content("You Move Right Succesfully", "text/plain");
    }); 

    srv.listen("localhost", 8080);
}


























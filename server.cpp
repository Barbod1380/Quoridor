#include <httplib.h>
#include <iostream>
 
using namespace std;

int main(void)
{
    using namespace httplib;
 
    Server srv;
    int Players_Counter = 0;
    int Number_Of_Players;


    cout << "Input Number Of Players" << endl;
    cin >> Number_Of_Players;


    while( Number_Of_Players > 4 || Number_Of_Players < 2 )
    {
        cout << "Players Number Should be 2 or 3 or 4" << endl;
        cin >> Number_Of_Players;
    }
 
    srv.Get("/join", [](const Request& req, Response& res)
    { 
        res.set_content("Welcome", "text/plain");
    }); 

    srv.listen("localhost", 8080);
}

















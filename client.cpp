#include <httplib.h>

int main()
{
    httplib::Client cli("localhost", 8080);
 
    auto res = cli.Get("/join");
    std :: cout << res->status << std :: endl; // 200
    std :: cout << res -> body << std :: endl;
}


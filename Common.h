int Players_Number;
int Current_Players_Number;


class Board_Maker
{
    public:
       
        Board_Maker();

        char** Board;
        int** Players_Location;

        void Board_View();
        void Set_Wall_On_Map( int, int, char );
        void Players_Movement( int, char );

    private:

};
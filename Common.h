class Board_Maker
{
    public:
       
        Board_Maker();

        char** Board;
        std :: string** Players_Name;
        int** Players_Location;
        bool** Movement_Allowed;
        void Set_Players_On_Map( int );
        void Board_View( int );
        void Set_Wall_On_Map( int, std :: string );
        void Players_Movement( int, char );
        std :: string Can_Go_There( int, char );


    private:

};


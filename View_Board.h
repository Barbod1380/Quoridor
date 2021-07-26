class Board
{
    public:
        
        Board( bool );

        void View();
        void Input();
        void Logic();
        void In_Board_Check();
        void Game_Check();

        bool GameOver;
        bool Out_Of_Board;

        int x, y;


    private:

        enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
        Direction dir;
};
#include <iostream>

using namespace std;

void view()
{
    for( int row = 0; row < 34; row++ )
    {
        if( row % 3 == 0 )
        {
            for( int column = 0; column < 34; column++ )
            {
                cout << 'e' << " ";
            }
        }
        else
        {
            for( int column = 0; column <= 44; column += 4 )
            {
                cout << 'e' << "     ";
            }
        }
        cout << endl;
    }
}

int main()
{
    view();
}

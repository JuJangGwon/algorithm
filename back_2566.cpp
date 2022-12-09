#include <iostream>

using namespace std;

int map[9][9];

int main()
{
    int result = -1;
    int result_x= 0;
    int result_y = 0;
    
    for (int i =0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (result < map[i][j])
            {
                result = map[i][j];
                result_x = i+1;
                result_y = j+1;
            }
        }
    }
    cout << result << endl << result_x << " " << result_y;
    return 0;
}
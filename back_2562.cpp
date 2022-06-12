#include <iostream>

using namespace std;

//
//
// 
//
//
int main(void)
{
    int i[9];
    int max = 0;
    int max_num;
    for (int j = 0; j < 9; j++)
    {
        cin >> i[j];
        if (max <= i[j])
        {
            max = i[j];
            max_num = j + 1;
        }
    }
    cout << max << endl << max_num;

    return 0;
}
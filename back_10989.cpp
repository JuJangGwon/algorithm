#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int i;
    int v;
    int d[10001] = {0, };

    cin >> i;
    for (int j = 0; j < i; j++)
    {
        cin >> v;
        d[v]++;
    }
    for (int j = 0; j < 10001; j++)
    {
        for (int x = 0; x < d[j]; x++)
        {

        }
    }
    return 0;
}
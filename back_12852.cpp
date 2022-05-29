#include <iostream>

using namespace std;

int map[1000001];
int track[1000001];

int main()
{
    int a;
    int num = 0;
    cin >> a;
    map[1] = 0;
    for (int i = 2; i <= a; i++)
    {
        map[i] = map[i-1] + 1;
        track[i] = i - 1;
        if (i % 3 == 0)
        {
            if (map[i/3] + 1 < map[i])
            {
                map[i] = min(map[i],map[i/3] + 1);
                track[i] = i / 3;
            }
        }
        if (i % 2 == 0)
        {
            if (map[i/2] + 1 < map[i])
            {
            map[i] = min(map[i/2] + 1,map[i]); 
            track[i] = i / 2;
            }
        }
    }
    cout << map[a] << "\n";
    while (a != 0)
    {
        cout << a << " ";
        a = track[a];
    }
    return 0;
}
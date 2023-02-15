#include <iostream>
#include <set>
#include <cmath>
#include <string>

using namespace std;

string map[1001];

int main()
{
    int N, k;
    bool clear;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> map[i];
    }
    for (int i = 1; i <= map[1].length(); i++)
    {
        set<string> s;
        clear = true;
        for (int j = 1; j <= N; j++)
        {
            // string c = map[j].substr(map[1].length() - i, map[1].length());
            // cout << c << endl;
            s.insert(map[j].substr(map[1].length() - i, map[1].length()));
            if (s.size() != j)
            {
                clear = false;
            }
        }
        if (clear == true)
        {
            cout << i;
            return 0;
        }
    }
}
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> mp;
    int a, b;

    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        string x, y;
        cin >> x >> y;
        mp.insert(make_pair(x,y));
    }
    for (int i = 0; i < b; i++)
    {
        string x;
        cin >> x;
        cout << mp.find(x)->second << '\n';
    }
    return 0;
}
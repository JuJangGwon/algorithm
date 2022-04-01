#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin >> a;
    for (int i =0 ; i < a; i++)
    {
        int x,y;
        cin >> x >> y;
        cout << x+y << "\n";
    }
    return 0;
}
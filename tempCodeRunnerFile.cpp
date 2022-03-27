#include <iostream>
#include <cmath>

using namespace std;

int sum;
int a, b, c;

void find(int x, int y, int size)
{
    if (c == x && b == y)
        cout << sum;
    if (size == 1) 
    {
        sum++;
        return ;
    }
    find(x,y,size /2);
    find(x + size /2,y,size /2);
    find(x,y + size / 2,size /2);
    find(x + size /2,y + size / 2,size /2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    find(0,0,pow(2, a);

    return 0;
}
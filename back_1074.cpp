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
    if (x > b  && y > c)
    {
        sum+= size * size;
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
    int size = pow(2, a);
    find(0,0, size);

    return 0;
}
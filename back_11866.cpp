#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a, b;
    queue<int> qu;

    cin >> a >> b;
    for(int i = 1; i <= a; i++)
    {
        qu.push(i);
    }
    cout << "<";
    while (qu.empty() == false)
    {
        for(int i = 0; i< b - 1; i++)
        {
            int temp = qu.front();
            qu.pop();
            qu.push(temp);
        }
        if (qu.size() != 1)
        {
        cout << qu.front() <<", ";
        }
        else 
        {
        cout << qu.front() <<">";
        }
        qu.pop();
    }
    return 0;
}
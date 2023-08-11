#include <queue>
#include <iostream>

using namespace std;

int main()
{
    queue<int> q;
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        q.push(i + 1);
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}
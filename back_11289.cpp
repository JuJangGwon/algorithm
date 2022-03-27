#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct cmp {
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main()
{
   ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    priority_queue<int, vector<int>, cmp > pq;
    int a;

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int v;
        cin >> v;
        if(v == 0)
        {
            if (pq.empty() == true)
                cout << "0" << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(v);
    }
    return 0;
}
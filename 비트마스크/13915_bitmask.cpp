#include <iostream>
#include <memory.h>
#include <set>

using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        set <int> s;
        for (int i =0; i < num; i++)
        {
            int t,temp = 0; 
            cin >> t;
            while (t != 0)
            {
                temp |= (1 << t % 10);
                t/=10;
            }
            s.insert(temp);
        }
            cout << s.size() << "\n";

    }
}
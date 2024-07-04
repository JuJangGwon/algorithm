#include <iostream>
#include <vector>
 
using namespace std;
 
vector<pair<int, int>> vec;
 
int main()
{
    int total = 0;
 
    int a;
    for (int i = 0; i < 9; i++)
    {
        cin >> a;
        vec.push_back(make_pair(a, 0));
        total += a;
    }
 
    total -= 100;
 
    for (int i = 0; i < 8; i++)
    {
        bool flag = 0;
        for(int j =  i+ 1; j < 9; j++)
        {
            if (vec[i].first + vec[j].first == total)
            {
                vec[i].second = 1;
                vec[j].second = 1;
                flag = 1;
            }
        }
        if (flag) break;
    }
 
    for (int i = 0; i < 9; i++)
    {
        if (!vec[i].second)
        {
            cout << vec[i].first << "\n";
        }
    }
    return 0;
}
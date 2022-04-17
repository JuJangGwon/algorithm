#include <iostream>
#include <algorithm>

using namespace std;

int number[9];
int num[9];
bool bnum[9];
int a, b;


void dfs(int c, int d)
{
    if (d == b)
    {
        for (int i = 0; i < b; i++)
        {
            cout << num[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = c; i < a; i++)
        {
            if (!bnum[i])
            {
                bnum[i] = true;
                num[d] = number[i];
                 dfs(c, d+1);
                bnum[i] = false;
            }
        }
    }
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        cin >> number[i];
    }
    sort(number, number + a);
    dfs(0,0);
    return 0;
}
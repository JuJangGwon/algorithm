#include <iostream>

using namespace std;

bool v[9];
int result[9];

int a, b;


void dfs(int k)
{
    if (k == b)
    {
        for (int i =0 ; i < b; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return ;
    }
    for (int i = 0; i < a; i++)
    {
        if (!v[i+1])
        {
            result[k] = i+1;
            v[i+1] = true;
            dfs(k+1);
            v[i+1] = false;
            result[k] = 0;
         }
    }
}

int main()
{
    cin >> a >> b;
    dfs(0);
    return 0;
}
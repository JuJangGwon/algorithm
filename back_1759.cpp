#include <iostream>
#include <algorithm>

using namespace std;

char ccc[16];
char result[16];
int l, c;
bool used[16];

void dfs(int a, int b,int mo, int ja)
{
    if (b == l)
    {
        if (mo >= 1 && ja >= 2)
        {
            cout << result << "\n";
        }
        return ;
    }
    for (int i = a; i < c; i++)
    {
        if (!used[ccc[i]])
        {
            result[b] = ccc[i];
            used[ccc[i]] = true;
            if (ccc[i] == 'a' || ccc[i] == 'e' || ccc[i] == 'i' || ccc[i] == 'u' || ccc[i] == 'o')
                dfs(i,b + 1,mo + 1,ja);
            else
                dfs(i,b+1,mo,ja +1);
            used[ccc[i]] = false;
        }
    }
}

int main()
{
    cin >> l >> c;
    for (int i  = 0; i < c; i++)
    {
        cin >> ccc[i];
    }
    sort(ccc,ccc+c);
    dfs(0,0,0,0);
}
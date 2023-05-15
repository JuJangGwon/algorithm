#include <iostream>
#include <algorithm>

using namespace std;

char input[16];
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
        if (!used[input[i]])
        {
            result[b] = input[i];
            used[input[i]] = true;
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'u' || input[i] == 'o')
                dfs(i,b + 1,mo + 1,ja);
            else
                dfs(i,b+1,mo,ja +1);
            used[input[i]] = false;
        }
    }
}

int main()
{
    cin >> l >> c;
    for (int i  = 0; i < c; i++)
    {
        cin >> input[i];
    }
    sort(input,input+c);
    dfs(0,0,0,0);
}
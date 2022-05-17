#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a;
string str[11];
int b[11];
bool c[11];
bool ov[27];
int mm;

void make()
{
    int ss = 0;
    for (int i = 1 ; i<= a; i++)
    {
        int sum = 0;
        for (int j = 0; j < str[i].size(); j++)
        {
            sum *= 10;
            sum += b[str[i][j]-'A'];
        }
        ss += sum;
    }
    mm = max(mm,ss);
}

void dfs(int num)
{
    if (num == 10)
    {
        make();
        return ;
    }
    for (int i = 0; i < 10; i++)
    {
        if (c[i] == false)
        {
            b[num] = i;
            c[b[num]] = true;
            dfs(num+1);
            c[b[num]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        cin >> str[i];
    }
    dfs(0);
    cout << mm;
}
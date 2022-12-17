#include <iostream>

using namespace std;

int n;
int result = 2111111111;
int result2;
int quest[4];

int mp[16];
int mf[16];
int ms[16];
int mv[16];
int mcost[16];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i =0; i < 4; i++)
    {
        cin >> quest[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mp[i] >> mf[i] >> ms[i] >> mv[i] >> mcost[i];
    }
    for (int i =1; i < (1 << n); i++)
    {
        int p = 0;
        int s = 0;
        int f = 0;
        int v = 0;
        int cost = 0;
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp |= (1 << j);
                p += mp[j];
                s += ms[j];
                f += mf[j];
                v += mv[j];
                cost += mcost[j];
            }
        }
        if (p >= quest[0] && s >= quest[1] && f >= quest[2] && v >= quest[3] && result > cost)
        {
            result = min(result,cost); 
            result2 = temp;
        }
    }
    if (result == 2111111111)
    {
        cout << "-1";
        return 0;
    }
    cout << result << "\n";

    for (int i = 0; i <= 15; i++)
    {
        if (result2 & (1 << i))
        {
            cout << i+1 << " ";
        }
    }
}
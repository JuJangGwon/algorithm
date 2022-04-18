#include <iostream>
#include <algorithm>

using namespace std;

int a, b;
int num[9];
int arr[9];
bool bnum[9];

void dfs(int c, int d)
{
    if (d == b)
    {
        for (int i =0; i < d; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }
    else
    {
        int c = -11;
        for (int i = 0; i < a; i++)
        {
            {
                if(!bnum[i] && c != num[i])
                {
                    bnum[i] = true;
                    c = num[i];
                    arr[d] = num[i];
                    dfs(i + 1,d+1);
                    bnum[i] = false;
                }
            }
        }
    }
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        cin >> num[i];
    }
    sort(num,num+a);
    dfs(0,0);
    return 0;
}

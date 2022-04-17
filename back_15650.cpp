#include <iostream>
#include <vector>

using namespace std;

int a, b;
int arr[9];
int used [9];

void dfs(int c, int d)
{
    if (d == b)
    {
        for (int i = 0; i < b; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }
    else
    {
        for (int i = c; i <= a; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                arr[d] = i;
                dfs(i + 1,d + 1);
                used[i] = false;
            }
        }
    }

}
int main()
{
    cin >> a >> b;
    dfs(1,0);
    return 0;
}
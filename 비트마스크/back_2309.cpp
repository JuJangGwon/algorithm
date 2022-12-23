#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n[9];
    int sum =0;

    for (int i = 0; i < 9; i++)
    {
        cin >> n[i];
        sum += n[i];
    }
    sort(n,n+9);
    for (int j = 0; j < (1 << 9); j++)
    {
        int count = 0;
        int tempsum = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((j & (1 << i)))
            {
                count++;
                tempsum +=n[i];
            }
        }
           if (count == 2 && sum - tempsum == 100)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (!(j & (1 << i)))
                        cout << n[i] << "\n";
                }
                return 0;
            }
    }
}
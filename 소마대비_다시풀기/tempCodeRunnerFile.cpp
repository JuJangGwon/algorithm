#include <iostream>

using namespace std;

int map[100001];

int main()
{
    int N, K;
    int sum = 0;
    int pivot = 1;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> map[i];
    }

    for (int i = 1; i <= N; i++)
    {
        sum += map[i];
        if (sum > K)
        {
            cout << i;
            return 0;
        }
    }
    if (sum <= K)
    {
        for (int i = N; i >= 1; i--)
        {
            sum += map[i];
            if (sum > K)
            {
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}
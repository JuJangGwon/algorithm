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
    while (sum <= K && pivot <= N)
    {
        sum += map[pivot];
        pivot++;
    }
    if (sum >= K)
    {
        cout << pivot - 1;
        return 0;
    }
    while (sum < K && pivot > 0)
    {
        sum += map[pivot];
        pivot--;
    }
    cout << pivot + 1;
    return 0;
}
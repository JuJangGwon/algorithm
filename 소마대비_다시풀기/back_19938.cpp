#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    N -= K * (K + 1) / 2;
    if (N < 0)
        cout << -1;
    else
    {
        N %= K;
        if (N == 0)
            cout << K - 1;
        else
            cout << K;
    }
}
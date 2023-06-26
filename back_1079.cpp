#include <iostream>

using namespace std;

int main(void)
{
    long long X, Y;

    int low = 0, high = 2111111111;
    int result = -1;
    cin >> X >> Y;
    int Z = (Y * 100) / X;

    while (low <= high)
    {

        int mid = (low + high) / 2;
        int temp = (100 * (Y + mid)) / (X + mid);

        if (Z >= temp)
        {
            result = mid + 1;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << "\n";
    return 0;
}
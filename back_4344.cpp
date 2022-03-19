#include <iostream>

using namespace std;

int main()
{
    int a;

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int j;
        int sum = 0;
        cin >> j;
        for(int c =0 ; c < j; c++)
        {
            int v;
            cin >> v;
            sum += v;
        }
        cout << sum << " , " << j;
        printf("%.3f",(float)sum / j);
    }
    return 0;
}
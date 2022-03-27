#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sum;
    vector<int> v;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, p, j;

    cin >> n >> m;
    for (int i =0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p >> j;
        sum = 0;
        for (int t = p; t <= j; t++)
        {
            sum += v[t-1];
        }
        cout << sum<< "\n";
    }
    return 0;
}
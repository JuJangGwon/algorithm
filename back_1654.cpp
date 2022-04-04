#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> v;
    int a, b;
    long long t = 0;
    long long min = 1;
    long long max = 1;
    cin >> a >> b;
    
    for (int i = 0; i < a; i++)
    {
        int c;
        cin >> c;
        if (c > max)
            max = c;
        v.push_back(c);
    }
    while (min <= max)
    {
        long long mid = (min + max) / 2;
        int sum = 0;

        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i] / mid;
        }
        if (sum >= b)
        {
            min = mid + 1;
            t = mid;
        }
        else if (sum < b)
        {
            max = mid - 1;
        }
    }
    cout << t;
}
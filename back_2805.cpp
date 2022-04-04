#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tree, m, down, up = 0;
    long long result = 0;
    vector <int> v;
    down = 1;
    result = 0;
    cin >> tree >> m;
    for (int i =0 ; i < tree; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        up = max(v[i], up);
    }
    while (down <= up)
    {
        int mid = (down + up) / 2;
        long long sum = 0;
        for (int i =0; i < tree; i++)
        {
            if (mid < v[i])
             sum += v[i] - mid;
        }
        if (sum >= m)
        {
            if (result < mid) 
                result = mid;
            down = mid + 1;
        }
        else
        up = mid - 1;
    }
    cout << result;

    return 0;
}
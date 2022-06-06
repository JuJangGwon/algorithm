#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, result;

int main()
{
    cin >> n;
    v.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (v.back() < a)
        {
            v.push_back(a);
            result++;
        }
        else
        {
            int l = lower_bound(v.begin(),v.end(), a) - v.begin();
            v[l] = a;
        }
    }
    cout << result;
}
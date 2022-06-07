#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, result;
int res[1000001];
int main()
{
    cin >> n;
    v.push_back(-1000000005);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (v.back() < a)
        {
            v.push_back(a);
            res[result] = a;
            result++;
        }
        else
        {
            int l = lower_bound(v.begin(),v.end(), a) - v.begin();
            res[result] = a;
            v[l] = a;
        }
    }
    cout << result << "\n";
    for (int i = 0; i < result; i++)
    {
        cout << res[i] << " ";
    }

}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> vv, vv1;
    string s;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> s;
        vv.push_back(s);
    }
   // sort(vv.front(), vv.end());
    for (int j = 0; j < m + n - 1; j++)
    {
        if (vv[j] == vv[j + 1])
        {
            vv1.push_back(vv[j]);
        }
    }
    cout << vv1.size() << "\n";
    for (int i = 0; i < vv1.size(); i++)
    {
        cout << vv1[i] << "\n";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string a;
    cin >> a;
    vector<int> v;
    for (int i = 0; i < a.size(); i++)
    {
        v.push_back(a[i]-48);
    }
    sort(v.begin(), v.end());
    for (int i = a.size() - 1; i >= 0; i--)
    {
        cout << v[i]; 
    }
    return 0;
}
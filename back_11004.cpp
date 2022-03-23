#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a, b;
    vector<int> v;
    cin >> a >> b;
    for(int i = 0; i < a; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    cout << v[b-1];
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector <int> a;
    vector <int> b;
    int c;

    cin >> c;
    for (int i =0 ; i < c; i++)
    {
        int d;
        cin >> d;
        a.push_back(d);
        b.push_back(d);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    
    for (int i =0 ; i < c; i++)
    {
        cout << lower_bound(b.begin(),b.end(),a[i]) - b.begin() << " ";
    }
    return 0;
}
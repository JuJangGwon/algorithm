#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

void bs(int b)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = (start + end) / 2;

    while (end - start >= 0)
    {
        mid = (start + end) / 2;
        if (v[mid] == b)
        {
            printf("1\n");
            return ;
        }
        else if (v[mid] > b)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    printf("0\n");
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    cin >> b;
    for (int i =0; i<b; i++)
    {
        int t;
        cin >> t;
        bs(t);
    }
    return 0;
}
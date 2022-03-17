#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dd;
    int a;
    int b;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        scanf("%d",&dd);
        bs(dd);
    }
    return 0;
}
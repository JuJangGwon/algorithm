#include <iostream>
#include <algorithm>

using namespace std;

bool Cmp(int A, int B)
{
    if (A > B) return true;
    return false;
}


int main()
{
    int rank_a[50];
    int a[50];
    int b[50];
    int c, sum = 0;;

    cin >> c;
    for (int i = 0; i < c; i++)
    {
        rank_a[i] = 1;
        cin >> a[i];
    }
    for (int i = 0; i < c; i++)
    {
        cin >> b[i];
    }
    sort(a, a + c);
    sort(b, b + c, Cmp);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(rank_a[i] < rank_a[j])
                rank_a[i]++;
        }
    }
    for (int i = 0; i < c; i++)
    {
        sum += a[i] * b[i];
    }
    cout << sum;
    return 0;
}
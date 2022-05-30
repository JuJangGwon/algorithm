#include <iostream>

using namespace std;

int map[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        cin >> map[i];
    }
    int left = 1;
    int right = a;
    int mins = 2147483647;
    int lefta;
    int righta;

    while (left < right)
    {
        int sum = (map[left] + map[right]);
        if (abs(sum) < mins)
        {
            mins = abs(sum);
            lefta = map[left];
            righta = map[right];
        }
        if (sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << lefta << " " << righta;
    return 0;
}
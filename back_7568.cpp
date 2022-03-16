#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
    int num;

    pair<int, int>d[50];

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> d[i].first >> d[i].second;
    }
    int rank;
    for (int i = 0; i < num ; i++)
    {
        rank = 1;
        for (int j = 0; j < num; j++)
        {
            if (d[i].first < d[j].first && d[i].second < d[j].second)
            {
                rank++;
            }
        }
        cout << rank << " ";
    }
    return 0;
}
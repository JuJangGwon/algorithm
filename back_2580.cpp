#include <iostream>
#include <vector>

using namespace std;

bool finish = false;

int sdoku[10][10];
vector<pair<int, int> > v;

bool check(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (sdoku[i][x] == sdoku[y][x] && i != y)
            return false;
        if (sdoku[y][i] == sdoku[y][x] && i != x)
            return false;
    }
    int xx = x / 3;
    int yy = y / 3;
    for (int i = yy  * 3; i < yy * 3 + 3; i++)
    {
        for (int j = xx * 3; j < xx * 3 + 3; j++)
        {
            if (sdoku[i][j] == sdoku[y][x] && i != y && j != x)
                return false;
        }   
    }
    return true;
}
void view_sdoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j =0; j< 9; j++)
        {
            cout << sdoku[i][j] << " ";
        }
        cout << "\n";
    }
}
void make_sdoku(int num)
{
    if (num == v.size() && finish == false)
    {
        finish = true;
        view_sdoku();
        return ;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (finish == true)
                return ;
        sdoku[v[num].second][v[num].first] = i;
        if (check(v[num].first,v[num].second))
        {    
            make_sdoku(num+1);
        }
        sdoku[v[num].second][v[num].first] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j< 9; j++)
        {
            cin >> sdoku[i][j];
            if (sdoku[i][j] == 0)
                v.push_back(make_pair(j,i));
        }
    }
    make_sdoku(0);
    return 0;
}
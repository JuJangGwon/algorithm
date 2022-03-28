#include <iostream>
#include <string>

using namespace std;

int c[21];
void add(int a)
{
    cout << c[a-1];
    c[a] = 1;
    cout << c[a-1];
}

void remove(int a)
{
    c[a] = 0;
}
int check(int a)
{
    return c[a];
}
void toggle(int a)
{
    if (c[a] == 0)
        c[a] = 1;
    else
        c[a] = 0;
}
void all()
{
        cout << "*";

    for (int i = 1; i <= 20; i++)
        c[i] = 1;
}
void clear()
{
    for (int i = 1; i <= 20; i++)
        c[i] = 0;
}
int main()
{
    int num;
    for (int i = 0; i < 20; i++)
        c[i] = 0;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string a;
        cin >> a;
        if (a == "all")
        {
            all();
        }
        else if (a == "clear")
        {
            clear();
        }
        else if (a[0] == 'c')
        {
            int o;
            cout << a[5];

            if(a.size() == 8)
            {
                o = (a[6] - 48) * 10 + (a[7] - 48);
            }
            else
                o = (a[6] - 48);
            cout << check(o) << "\n";
        }
        else if (a[0] == 'r')
        {
            int o;
            if(a.size() == 9)
            {
                o = (a[7] - 48) * 10 + (a[8] - 48);
            }
            else
                o = (a[7] - 48);
            remove(o);
        }
        else if (a[0] == 't')
        {
            int o;
            if(a.size() == 9)
            {
                o = (a[7] - 48) * 10 + (a[8] - 48);
            }
            else
                o = (a[7] - 48);
            toggle(o);
        }
         else if (a[0] == 'a')
        {
            int o;
            if(a.size() == 6)
            {
                o = (a[4] - 48) * 10 + (a[5] - 48);
            }
            else
                o = (a[4] - 48);
            cout << o;
            add(o);
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

char node[27][2];

void jeon(char o)
{
    if (o == '.')
    {
        return ;
    }
    else 
    {
        cout << o;
        jeon(node[o-'A'][0]);
        jeon(node[o-'A'][1]);
    }
}
void joong(char o)
{
    if (o == '.')
    {
        return ;
    }
    else 
    {
        joong(node[o-'A'][0]);
        cout << o;
        joong(node[o-'A'][1]);
    }
}
void who(char o)
{
    if (o == '.')
    {
        return ;
    }
    else 
    {
        who(node[o-'A'][0]);
        who(node[o-'A'][1]);
        cout << o;
    }
}
int main()
{
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        char b, c, d;
        cin >> b >> c >> d;
        node[b- 'A'][0] = c;
        node[b- 'A'][1] = d;
    }
    jeon('A');
    cout << "\n";
    joong('A');
    cout << "\n";
    who('A');
    cout << "\n";
    return 0;
}
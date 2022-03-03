#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int time;
    int a;
    string b;

    cin >> time;
    for (int i = 0; i < time; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < b.size(); j++)
        {
            for (int x = 0; x < a; x++)
            {
                cout << b[j];
            }
        }
        cout << endl;
    }
    return 0;
}
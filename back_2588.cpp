#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a;
    string str;

    cin >> a >> str;

    for (int i = 0; i < 3; i++)
    {
        cout << (str[2 - i] - 48) * a << "\n";
    }
    cout << stoi(str) * a;
    return 0;
}
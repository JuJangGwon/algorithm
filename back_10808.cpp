#include <iostream>
#include <string>

using namespace std;

int arr[27];

int main()
{
    string c;
    cin >> c;
    for (int i = 0; i < c.size();i++)
    {
        arr[int(c[i]-'a')]++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size;
    vector <string> str;
    string c;
    cin >> c;
    size = c.length();
    for (int i = 0; i < size; i++)
    {
        str.push_back(c);
        c.erase(c.begin());
    }
    sort(str.begin(), str.end());
    for (int i = 0 ; i< str.size(); i++)
    {
        cout << str[i] << "\n";
    }
    return 0;
}
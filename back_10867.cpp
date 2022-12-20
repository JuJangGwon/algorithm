#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> s;
    int num;
    cin >> num;

    for (int i =0; i < num; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    
    for (set<int>::iterator i = s.begin(); i != s.end();i++)
    {
        cout << *i << " ";
    }
}
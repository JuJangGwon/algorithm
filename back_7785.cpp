#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> s;

    int n;
    cin >> n;
    
    for (int i =0; i < n;i++)
    {
        string s1,  s2;
        cin >> s1 >> s2;
        if (s2 == "enter")
        {
            s.insert(s1);
        }
        else
        {
            s.erase(s1);
        }
    }

    for (set<string>::reverse_iterator i = s.rbegin(); i != s.rend();i++)
    {
        cout << *i << "\n";
    }
}
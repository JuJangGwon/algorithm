#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string answer;
    cin >> s;
    for (int i = 0; i < s.size();i++)
    {
        int x = 0;
        while(s[i] == 'X')
        {
            i++;
            x++;
        }
        if (x > 0)
        {
        if (x % 2 == 1)
        {
            cout << "-1";
            return 0;
        }
        if (x % 2 == 0)
        {
            for (int j = 0; j < x / 4;j++)
            {
                answer+= "AAAA";
            }
            x %= 4;
            if (x == 2)
            {
                answer+= "BB";
            }
        }
        }
        if (s[i] == '.')
        {
            answer+='.';

        }
       
    }
    cout << answer;
    return 0;
}
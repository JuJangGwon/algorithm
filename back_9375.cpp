#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <pair<int, string> > mp;
    int cas;
    cin >> cas;
    for (int i = 0; i < cas; i++)
    {
        int o;
        bool find = false;
        cin >> o;
        string s1, s2;
        for (int v = 0; v < o; v++)
        {
        cin >> s1 >> s2;
        if (mp.size() == 0)
        {
            mp.push_back(make_pair(1,s2));
        }
        else
        {
            for (int j = 0; j < mp.size(); j++)
            {
                if (mp[j].second == s2)
                {
                    find = true;
                    mp[j].first++;
                    break;
                }
            }
            if (find == false)
            {
                mp.push_back(make_pair(1,s2));
            }
        }
        }
        int cas2 = 1;
        int sum = 0;
        for (int i = 0; i < mp.size(); i++)
        {
            cas2 *= mp[i].first + 1;
            sum += mp[i].first; 
        }
        //if (mp.size() != 1)
        //{
       //     cas2 += sum;
      //  }
        cout << cas2 - 1<< "\n";
        mp.clear();
    }
  
    return 0;
}
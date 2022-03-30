#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    int testcase;
    deque<int> deq;
    cin >> testcase;

    bool front = true;
    bool error = false;
    for (int i =0; i < testcase; i++)
    {
        if(deq.empty())
            deq.clear();
        string str;
        string str2;
        int word_N;
        front = true;
        error = false;
        cin >> str;
        cin >> word_N;
        cin >> str2;

        for (int j =0; j <str2.size(); j++)
        {
            if (str2[j] >= '0' && str2[j] <= '9')
            {
                int o = str2[j] - 48;
                if (str2[j + 1] >= '0' && str2[j + 1] <= '9')
                {
                    o *= 10;
                    o += str2[j] - 48;
                    j++;
                }
                deq.push_back(o);
            }
        }
        for (int j =0; j < str.size(); j++)
        {
            if (str[j] == 'R')
            {
                if (front == true)
                    front = false;
                else
                    front = true;
            }
            else if(str[j] == 'D')
            {
                if (deq.size() == 0)
                {
                    error = true;
                    j = str.size();
                }
                if (front == true)
                    deq.pop_front();
                else
                    deq.pop_back();
            }
        }
        if (error == true)
        {
            cout << "error\n";
        }
        else
        {
            cout << "[";
            while (deq.size() > 0)
            {
                if (front == true)
                {
                cout << deq.front();
                deq.pop_front();
                }
                else
                {
                    cout << deq.back();
                    deq.pop_back();
                }
                if (deq.size() != 0)
                    cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
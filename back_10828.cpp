#include <iostream>
#include <string>
using namespace std;

class stack
{
    private:
    int n[100000];
    int _size = 0;

    public:
    void push(int i)
    {
        n[_size] = i;
        _size++;
    }
    bool empty()
    {
        if (_size == 0)
            return 1;
        else
            return 0;
    }
    int size()
    {
        return _size;
    }
    int top()
    {
        if (_size == 0)
            return -1;
        else
            return n[_size - 1];
    }
    int pop()
    {
        if (_size == 0)
            return -1;
        _size--;
        return n[_size];
    }
};

int main()
{   
    int num;
    string str;
    cin >> num;
    stack st;

    for (int i = 0; i <= num; i++)
    {
        getline(cin, str);
        if (str == "pop")
        {
            cout << st.pop() << endl;
        }
        else if (str == "top")
        {
            cout << st.top() << endl;
        }
        else if (str == "empty")
        {
            cout << st.empty() << endl;
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        else if (str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h')
        {
            string str_;
            for(int j = 5; j <  str.size(); j++)
            {
                str_.push_back(str[j]);
            }
            st.push(stoi(str_));
        }

    }
    return 0;
}
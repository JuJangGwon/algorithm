#include <iostream>
#include <string>

using namespace std;

int size = 0;
int _array[10000];
int pivot = 0;

int f_push(int x)
{
    _array[pivot + size] = x;
}

int back()
{
    if (size == 0)
        return -1;
    else
        return _array[pivot + size];
}

int front()
{
    if (size == 0)
        return -1;
    else 
        return _array[pivot];
}
int empty()
{
    if (size == 0)
        return 1;
    else
        return 0;
}
int f_pop()
{
    if (size == 0)
        return -1;
    else
    {
        int v = _array[pivot++];
        size--;
        return v;
    }
}
int f_size()
{
    return size; 
}

int main(void)
{
    int num;
    string str;

    cin >> num;
    for (int i = 0; i< 15; i++)
    {
        cin >> str;
        if (str == "front")
        {
            cout << front() << endl;
        }
        else if (str == "back")
        {
            cout << back() << endl;
        }
        else if (str == "size")
        {
            cout << f_size() << endl;
        }
        else if (str == "empty")
        {
            cout << empty() << endl;
        }
        else if (str == "pop")
        {
            cout << f_pop() << endl;
        }
        else if (str[0] == 'p' && str[1] == 'u' && str[2] == 's' && str[3] == 'h')
        {
            string str_;
            for(int j = 5; j <  str.size(); j++)
            {
                str_.push_back(str[j]);
            }
            f_push(stoi(str_));
        }
    }
    return 0;
}
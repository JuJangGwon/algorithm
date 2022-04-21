#include <iostream>

using namespace std;

int node[1000001][2];
int top;
int pivot;
int sizee = 0;

void who(int a)
{
    if (a == 0)
        return ;
    who(node[a][0]);
    who(node[a][1]);
    cout << a << "\n";
}

void make(int num)
{
    if (sizee == 0)
    {
        top = num;
        pivot = num;
        sizee++;
    }
    else
    {
        pivot = top;
        while (1)
        {
            if (pivot > num)
            {
                if (!node[pivot][0])
                {
                    node[pivot][0] = num;
                    break;
                }
                else
                {
                    pivot = node[pivot][0];
                }
            }
            else if (pivot < num)
            {
                if (!node[pivot][1])
                    {
                        node[pivot][1] = num;
                        break;
                    }
                else
                    pivot = node[pivot][1];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int number;
    while (cin >> number)
    {
        make(number);
    }
    who(top);
    return 0;
}
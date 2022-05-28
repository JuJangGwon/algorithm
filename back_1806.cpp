#include <iostream>

using namespace std;

int a, b;
int map[100001];
long long sum;
int siz = 1;
int m_size = 999999999;
int main()
{
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        cin >> map[i];
    }
    int start = 1;
    int end = 1;
    sum += map[start];
    
    while (start <= a && end <= a)
    {
        if (sum >= b)
        {
            m_size = min(m_size,siz);
            siz--;
            sum -= map[start];
            start++;
        }
        else
        {
            siz++;
            end++;
            sum += map[end];
        }
    }
    if (m_size == 999999999)
        m_size = 0;
    cout << m_size;
}
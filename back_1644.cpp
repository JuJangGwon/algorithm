#include <iostream>
#include <vector>

using namespace std;

bool prime[4000001];
vector<int> v;

int main()
{
    int a;
    cin >> a;
    for (int i = 2 ; i * i <= a; i++)
    {
        if (prime[i] == false)
        {
            for (int j = i + i; j <= a; j += i)
            {
                prime[j] = true;
            }
        }
    }
    for (int i = 2; i <= a; i++)
    {
        if (prime[i] == false)
        {
            v.push_back(i);
        }
    }
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    while (1)
    {
        if (sum > a)
        {
            sum -= v[left];
            left++;
        }
        else if (sum == a)
        {
            ans++;
            if (right >= v.size()) break;
            sum += v[right];
            right++;
        }
        else if (sum < a)
        {
            if (right >= v.size()) break;
            sum += v[right];
            right++;
        }
    }
    cout << ans;
}
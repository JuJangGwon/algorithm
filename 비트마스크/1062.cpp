#include <iostream>
#include <string>

using namespace std;

int word[51];
int n, k, m =0;

void check(int num)
{
    int t =0;
    for (int i =0; i < n; i++)
    {
        if ((word[i] & num) == word[i])
        {
            t++;
        }
    }
    m = max(t,m);
}

void dfs(int start, int num, int now)
{
    if (now == k)
    {
        check(num);
        return ;
    }
    else
    {
        for (int i =start; i < 26; i++)
        {
            if(!(num & (1 << (i))))
            {
                num |= 1 << (i);
                dfs(i+1,num,now+1);
                num &= ~(1 << (i));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int visited = 0;
    
    cin >> n >> k;
     
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 4; j < temp.size()-4; j++)
        {
            word[i] |= (1 << (temp[j]-'a'));
        }
    }
     if (k < 5)
    {
        cout << "0\n";
        return 0;
    }
    if (k == 26)
    {
        cout << n << "\n";
        return 0;
    }
	visited |= 1 << ('a'-'a');
    visited |= 1 << ('n'-'a');
    visited |= 1 << ('t'-'a');
    visited |= 1 << ('i'-'a');
    visited |= 1 << ('c'-'a');
    dfs(1,visited,5);
    cout << m << "\n";
}
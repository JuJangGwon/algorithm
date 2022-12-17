#include <iostream>
#include <string>

using namespace std;

int word[51];
int n, k, max_word =0;

void check(int num)                     // 조합으로 몇개의 단어를 만들수 있는지 체크
{
    int t =0;
    for (int i =0; i < n; i++)
    {
        if ((word[i] & num) == word[i])     // & 연산을 이용해 word[i]의 비트가 num 비트에 모두 포함 되는지 체크
        {
            t++;
        }
    }
    max_word = max(t,max_word);
}

void dfs(int start, int num, int now)               // dfs로 조합 만들기 
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
    
    int learned = 0;
    
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

    // 조합 만들 때 시간 초과 방지로 'a n t i c'를 미리 체크 해놓기
	learned |= 1 << ('a'-'a');     
    learned |= 1 << ('n'-'a');
    learned |= 1 << ('t'-'a');
    learned |= 1 << ('i'-'a');
    learned |= 1 << ('c'-'a');

    dfs(1,learned,5);
    cout << max_word << "\n";
}
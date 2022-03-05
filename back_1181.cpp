#include <iostream>
#include <algorithm> 
#include <string>

using namespace std; 

string st[20000];

int cmp(string a, string b) 
{ 
    if (a.length() == b.length()) 
    {
         return a < b; 
    } 
    else 
    {
         return a.length() < b.length(); 
    }
}

int main()
{ 
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) 
    { 
        cin >> st[i]; 
    } 
    sort(st, st + N, cmp); 
    for (int i = 0; i < N; i++)
    {
        if (st[i] == st[i - 1])
        {
             continue; 
        } 
        cout << st[i] << "\n";
    }
    return 0;
}
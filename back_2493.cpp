#include <iostream>
#include <stack>
#include <vector>
#define MAX 500001
using namespace std;

int n;
int arr[MAX];
stack<pair<int, int> > tops;

void Input()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
}
void Solution()
{
    for(int i=1; i<=n; i++)
    {
        while(!tops.empty())
        {
            if(tops.top().second>arr[i])
            {
                cout<<tops.top().first<<" ";
                break;
            }
            tops.pop();
        }
        if(tops.empty())
        {
            cout<<0<<" ";
        }
        tops.push(make_pair(i, arr[i]));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solution();
    return 0;
}
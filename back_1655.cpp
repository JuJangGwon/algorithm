#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> mmax;
priority_queue<int,vector<int>,greater<int> > mmin;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int o;
    cin >> o;

    for (int i = 0; i < o; i++)
    {
        int a;
        cin >> a;
        if (mmax.size() == mmin.size()) {
            mmax.push(a);
        }
        else {
            mmin.push(a);
        }
        if (!mmax.empty() && !mmin.empty() && mmax.top() > mmin.top()) 
        {
            int mmmaxx, mmmin;
            mmmaxx = mmax.top();
            mmmin = mmin.top();
            mmax.pop();
            mmin.pop();
            mmax.push(mmmin);
            mmin.push(mmmaxx);
        }
        cout << mmax.top() << '\n';
    }
    return 0;
}
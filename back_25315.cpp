#include <iostream>
#include <vector>

using namespace std;

int num;
pair<int,int>start_p[2501];
pair<int,int>end_p[2501];
int power[2501];
bool used[2501];
int arr[2501];
int re = 2111111111;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) 
{    
    int op = a.first*b.second + b.first*c.second + c.first*a.second; 
       op -= (a.second*b.first + b.second*c.first + c.second*a.first); 
       if (op > 0)
    return 1;  
      else if (op == 0)
    return 0; 
       else
     return -1;
}
int isIntersect(pair<pair<int,int>,pair<int,int> >x,pair<pair<int,int>,pair<int,int> >y)
{
    pair<int,int>a=x.first;
    pair<int,int>b=x.second;
    pair<int,int>c=y.first;
    pair<int,int>d=y.second;
    int ab= ccw(a,b,c)*ccw(a,b,d);
    int cd= ccw(c,d,a)*ccw(c,d,b);
    if(ab==0&& cd==0)
    {
        if(a>b)
        swap(a,b);
        if(c>d)
        swap(c,d);
        return c<=b&&a<=d;
        }
    return ab<=0&&cd<=0;
}
void check()
{
    int result = 0;
    for (int i = 0; i < num; i++)
    {
        int t = 0;
        for (int j = i+1; j < num; j++)
        {

          //  A = (end_p[arr[j]].first - end_p[arr[i]].first) * (start_p[arr[i]].second - end_p[arr[i]].second) - (end_p[arr[j]].second - end_p[arr[i]].second) * (start_p[arr[i]].first - end_p[arr[i]].first);
          //  B = (start_p[arr[j]].first - start_p[arr[i]].first) * (start_p[arr[i]].second - end_p[arr[i]].second) - (start_p[arr[j]].second - start_p[arr[i]].second) * (start_p[arr[i]].first - end_p[arr[i]].first);
             //   cout << A << ", " << B << " |  ";
            if(isIntersect(make_pair(start_p[arr[i]],end_p[arr[i]]),make_pair(start_p[arr[j]],end_p[arr[j]])))
            {
   
               // cout << "겹 ";
                t++;
            }
        }
        //cout << (t + 1) *  power[arr[i]] << " ";
        result += (t + 1) *  power[arr[i]];
        if (re <= result)
            return ;
    }
    //cout << result << "\n";
    re = min (re,result);
}

void sortt()
{
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                pair<int,int> tempp = start_p[i];
                start_p[i] = start_p[j];
                end_p[j] = tempp;
                temmp 
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        start_p[i] = make_pair(a,b);
        end_p[i] = make_pair(c,d);
        cin >> power[i];
    }
    sort();
    cout << re;
}
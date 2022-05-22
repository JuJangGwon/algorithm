#include <iostream>

using namespace std;

int n;
int node[100001];
int inorder[100001];
int postorder[100001];
// 1 2 3
// 1 2 3 [4] 5 6 7
void makepreorder(int a,int b,int c)
{
    if(b > n || node[b])
        return ;
    node[b] = postorder[a];
    // 왼
    makepreorder(a/ 2, b * 2 , a / 2);
    // 오
    makepreorder((a - 1),b*2+1,a/2);
}
// 7 
int main()
{
    cin >> n;
    for (int i =1 ; i<= n; i++)
    {
        cin >> inorder[i];
    }
    for (int i =1 ; i<= n; i++)
    {
        cin >> postorder[i];
    }
    makepreorder(n,1,0);
    for (int i = 1; i<= n; i++)
    {
        cout << node[i] << " ";
    }
    return 0;
}
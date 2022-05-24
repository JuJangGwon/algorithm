#include <iostream>

using namespace std;

int n;
int node[100001];
int inorder[100001];
int postorder[100001];
// 1 2 3
// 1 2 3 [4] 5 6 7
void makepreorder(int start,int end,int c)
{
    
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
    makepreorder(1,n,0);
    for (int i = 1; i<= n; i++)
    {
        cout << node[i] << " ";
    }
    return 0;
}
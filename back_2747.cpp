#include <iostream>

using namespace std;

int fibo(int n){

    int a = 0;
    int b = 1;
    int tmp;

    if(n == 1) return 1;
    if(n == 0) return 0;

    for(int i=0 ; i<n-1; i++)
    {
        tmp = b;
        b = a+b;
        a = tmp;
    }
    return b;
}

int main(void)
{
    int i;

    cin >> i;
    cout << fibo(i);

    return 0;
}
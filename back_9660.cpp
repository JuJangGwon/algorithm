#include <iostream>

using namespace std;

int main()
{
    long long n;
    int rest;
    cin>>n;
    rest = n%7;
    if(rest == 0)
        cout<<"CY";
    else if(rest == 2)
        cout<<"CY";
    else
        cout<<"SK";
    return 0;
}
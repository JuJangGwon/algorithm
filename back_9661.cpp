#include <iostream>

using namespace std; 

int main() 
{ 
    long long int n; 
    cin >> n;
    n = n%5; 
    if (n == 0 || n == 2) 
        cout << "CY"; 
    else 
        cout << "SK"; 
}
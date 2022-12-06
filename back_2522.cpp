#include <iostream>

using namespace std;

int main()
{
    int N;
 
    cin >> N;
 
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < (N-k) - 1; i++)
        {
            cout << " ";
        }
        for (int j = 0; j < k + 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
 
    for (int k = 0; k < N; k++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            cout << " ";
        }
        for (int i = 0; i < (N - k) - 1; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

#include <iostream>

using namespace std;

int main()
{
    int a;
    
    cin >> a;

    for (int i =1; i <= a;i++)
    {
        for (int j = 0; j < a* 2; j++)
        {
                if (j+1 <= i || j>= a*2-i)
                    cout << "*";
                else
                    cout << " ";
        }
        cout << "\n";
    }
      for (int i = 1; i <= a;i++)
    {
        for (int j = 0; j < a* 2; j++)
        {
                if (a - i > j || j+1 > a +i)
                    cout << "*";
                else
                    cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>

using namespace std;
int main()
 {
    string k;
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> k;
        for (int j = 0; j < 8; j++)
            if (k[j] == 'F' && (j+1) % 2 == 1 && (i+1) % 2 == 1)
                cnt++;
            else if (k[j] == 'F' && (j+1) % 2 == 0 && (i+1) % 2 == 0)  
                cnt++;
    }
    cout << cnt;
    return 0;
}

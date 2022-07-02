#include <iostream>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
int a;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    int b = (a-1) / 4;
    for (int i = 0; i <= b; i++)
    {
        cout << "long "; 
    }
    cout << "int";

    return 0;
} 
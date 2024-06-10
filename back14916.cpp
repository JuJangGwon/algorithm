#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1 || n == 3) {
        cout << -1;
        return 0;
    }

    int five = n / 5;
    int remainder = n % 5;

    while (five >= 0) {
        if (remainder % 2 == 0) {
            cout << five + remainder / 2;
            return 0;
        }
        five--;
        remainder += 5;
    }

    cout << -1;
    return 0;
}
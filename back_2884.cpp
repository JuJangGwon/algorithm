#include <iostream>

using namespace std;

int main(void)
{
    int hour, minute;

    cin >> hour >> minute;
    
    minute -=45;
    if (minute < 0)
    {
        minute = 60 + minute;
        hour--;
        if (hour < 0)
            hour = 23;
    }
    cout << hour << " " << minute;
    return 0;
}
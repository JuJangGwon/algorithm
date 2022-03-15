    #include <iostream>

    using namespace std;

    int main(void)
    {
        int a;
        int d = 5;
        int v = 0;
        int sum = 1;

        cin >> a;
        if (a == 1)
        {
            cout << "1"
            return 0;
        }
        if (a <= 7 && a > 1)
        {
            cout << "2";
            return 0;
        }
        while ((a > 0))
        {
            v = v + d++;
            a = a - v;
            sum++;
        }
        cout << sum;
        return 0;
    }
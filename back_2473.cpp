    #include <iostream>
    #include <algorithm>

    using namespace std;

    long long map[5001];
    long long mins = 3000000001;

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> map[i];
        }
        sort(map,map+n);
        int a_1;
        int a_2;
        int a_3;
        for (int i = 0;i < n-2; i++)
        {
            int a = i + 1;
            int b = n-1;
            while (a < b)
            {
                long long sums = map[a] + map[b] + map[i];
                if (abs(sums) < mins)
                {
                    mins = abs(sums);
                    a_1 = map[i];
                    a_2 = map[a];
                    a_3 = map[b]; 
                }
                if (sums < 0)
                {
                    a++;
                }
                else
                {
                    b--;
                }
            }
        }
        cout << a_1 << " " << a_2 << " " << a_3; 
        return 0;
    }
#include <iostream>
using namespace std;

int main(void)
{
    int N, L, D;
    cin >> N >> L >> D;

    int result;

    for (int i = 1;; i++)
    {
        if (D * i > N * L + (N - 1) * 5)
        {
            result = D * i;
            break;
        }
    }

    for (int n = 1; n <= N; n++)
    {
        int Start = n * L + (n - 1) * 5;
        int End = Start + 5;

        bool foundAnswer = false;

        for (int i = 1; D * i < End; i++)
        {
            if (Start <= D * i && D * i < End)
            {
                result = D * i;
                foundAnswer = true;
                break;
            }
            if (Start < D * i + 1 && D * i + 1 < End)
            {
                result = D * i + 1;
                foundAnswer = true;
                break;
            }
        }
        if (foundAnswer)
            break;
    }
    cout << result << "\n";
    return 0;
}
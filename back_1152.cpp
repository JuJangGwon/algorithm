#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int i = 0;
    int word_num;
    bool isword;
    string c;

    word_num = 0;
    isword = false;
    getline(cin, c);
    while (c[i])
    {
        if (c[i] == ' ')
            isword = false;
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
        {
            if (isword == false)
                word_num++;
            isword = true;
        } 
        i++;
    }
    cout << word_num;
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int num;
    int arr = 0;
    cin >> num;
    for (int i =0; i < num; i++)
    {
        string str;
        int number;
        cin >> str;

        if (str == "add")
        {
        	cin >> number;
            arr |= (1 << number);
        }
        else if (str == "remove")
        {
        	cin >> number;
            arr &=  ~(1 << number);
        }
        else if (str == "check")
        {
        	cin >> number;
			if (arr &  ( 1 << number))
                cout<<"1\n";
			else 
                cout<<"0\n";
        }
        else if (str == "toggle")
        {
        	cin >> number;
			arr ^=  (1 << number);

        }
        else if (str == "empty")
        {
            arr = 0;
        }
          else if (str == "all")
        {
            arr = (1 << 21) - 1;
        }
    }
}
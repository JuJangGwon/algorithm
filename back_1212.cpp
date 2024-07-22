#include <iostream>
#include <string>
#include <queue>
using namespace std;


int main()
{
	string eight;
	cin >> eight;
	queue<int> two;
	if (eight == "0")
		cout << 0;
	for (int i = 0; i < eight.size(); i++)
	{
		int tmp = int(eight[i] - '0');
		two.push(tmp / 4);
		tmp = tmp % 4;
		two.push(tmp / 2);
		tmp = tmp % 2;
		two.push(tmp);
	}
	for(int i=0;i<3;i++)
	{
		if (two.front() == 0)
			two.pop();
		else
			continue;
	}
	while (!two.empty())
	{
		cout << two.front();
		two.pop();
	}
}
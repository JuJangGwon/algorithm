#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count, temp, row = 0, col = 0;
	bool check = false;
	cin >> count;
	vector<vector<char>> sq(count, vector<char>(count, 0));

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cin >> sq[i][j];
		}
	}
	for (int i = 0; i < count; i++)
	{
		temp = 0;
		check = false;
		for (int j = 0; j < count; j++)
		{
			if (sq[i][j] == '.') temp++;
			else
			{
				temp = 0;
				check = false;
			}

			if (temp >= 2 && check == false)
			{
				row++;
				check = true;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		temp = 0;
		check = false;
		for (int j = 0; j < count; j++)
		{
			if (sq[j][i] == '.') temp++;
			else
			{
				temp = 0;
				check = false;
			}

			if (temp >= 2 && check == false)
			{
				col++;
				check = true;
			}
		}
	}
	cout << row << " " << col;
}
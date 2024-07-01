#include <iostream>
using namespace std;

int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= 1000; i++) {
		arr[i] = i + arr[i - 1];
	}

	while (N--) {
		int num;
		cin >> num;
		bool is_visit = true;
		for (int i = 1; arr[i] < num && is_visit; i++) {
			for (int j = i; arr[j] + arr[i] < num && is_visit; j++) {
				for (int k = j; arr[i] + arr[j] + arr[k] <= num && is_visit; k++) {
					if (arr[i] + arr[j] + arr[k] == num) {
						is_visit = false;
						cout << 1 << "\n";
						break;
					}
				}
			}
		}
		if (is_visit) {
			cout << 0 << "\n";
		}
	}
}
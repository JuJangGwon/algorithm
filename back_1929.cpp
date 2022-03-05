#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	bool a[1000001];
	int N, K;
	cin >> N >> K;

	a[0] = false;
	a[1] = false;
	for (int i = 2; i <= K; i++) {
		a[i] = true;
	}

	for (int i = 2; i <= sqrt(K); i++) {
		if (a[i]) {
			for (int j = i * i; j <= K; j += i) {
				a[j] = false;
			}

		}
	}
	for (int k = N; k <= K; k++) {
		if (a[k]) 
        {
			printf("%d\n", k);
		}
	}
    return 0;
}
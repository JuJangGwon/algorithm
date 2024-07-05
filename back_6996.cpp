#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    
	int test;
	cin >> test;

	for (int i = 0; i < test; i++) {
		string a1, a2,tmp1,tmp2;
		cin >> a1 >> a2;
		tmp1 = a1, tmp2 = a2;
		
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		
		if (a1 == a2) cout << tmp1 << " & " << tmp2 << " are anagrams.\n";
		else cout << tmp1 << " & " << tmp2 << " are NOT anagrams.\n";
	}
}
#include <iostream>
#include <algorithm>
using namespace std;

struct student{
	string name;
	int kr;
	int eg;
	int mth;
};

bool cmp(student s1, student s2){
	if(s1.kr > s2.kr) return true;
	else if(s1.kr == s2.kr){
		if(s1.eg < s2.eg) return true;
		else if(s1.eg == s2.eg){
			if(s1.mth > s2.mth) return true;
			else if(s1.mth == s2.mth){
				if(s1.name < s2.name) 
					return true;
			}
		}
	}
	return false;
}

int main(void){
	int n; 
	cin >> n;

	struct student S[n];
	for(int i=0; i<n; i++){
		cin >> S[i].name >> S[i].kr >> S[i].eg >> S[i].mth;
	}

	sort(S, S+n, cmp);
	for(int i=0; i<n; i++){
		cout << S[i].name << "\n";
	}

	return 0;
}
#include <iostream>
using namespace std;

int main() {

	int N,k=0,name[26]={0,};
	string tmp;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		name[tmp[0]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(name[i]>4){
			cout<<(char)(i+'a');
			k=1;
		}
	}
	if(k==0) cout<<"PREDAJA";
	return 0;
}
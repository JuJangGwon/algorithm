#include <iostream>
#include <vector>
using namespace std;


vector<int> v;

int main(){
  int n, x;
  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> x;
    v.insert(v.begin() + x, i); 
  }

  for(int i=n-1; i>= 0; i--){
    cout << v[i] << " ";
  }

  return 0;
}
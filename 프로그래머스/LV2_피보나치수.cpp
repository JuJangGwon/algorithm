#include <string>
#include <vector>

using namespace std;

int fibo(int n){
    int f[3] = {0,0,1};
    
    for(int i=1; i<n; i++){
        f[0] = f[1];
        f[1] = f[2];
        f[2] = (f[0] + f[1]) % 1234567;
    }
    return f[2];
}

int solution(int n) {
    return fibo(n);
}
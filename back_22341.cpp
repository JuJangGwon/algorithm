#include <iostream>

using namespace std;
int main(){
int a,b,c,d;

    c=a,d=a;
    while(b--){
        int y,x;
        cin >> y >> x;
        if(y>c||x>d) continue;
        int ny=y,nx=c,w=y*d;
        if(w<c*x){
            ny=c,nx=x;
        }
        c=ny,d=nx;
    }
    printf("%d",c*d);
}
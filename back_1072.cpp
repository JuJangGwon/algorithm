#include<iostream>
 
using namespace std;
 
int main(){
    int x,y;
    cin>>x>>y;

    long long z = (100 * y) / x;
    
    if(z>= 99){
        cout<<"-1"<<endl;
        return 0;
    }
    long long right = 1000000000;
    long long left = 0;
    
    while(left<=right){
        long long mid = left + right;
        mid = mid / 2;
        int temp = (100 * (y + mid)) / (x + mid);
        if(temp > z){
            right = mid-1;
        }
        else if(temp <= z){
            left = mid +1;
        }
    }
 
    cout<<left<<endl;

    return 0;
}

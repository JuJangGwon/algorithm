#include <iostream>
#include "math.h"
using namespace std;


int arr[10001];

int getSum(int *arr, int length,int limit) {
  int sum = 0;
  for (int i = 0; i < length; i++){
    sum += arr[i] > limit ? limit : arr[i];
  }
  return sum;
}

int main(){
  int n;
  int sum = 0;
  int min_n = 0;
  int max_n = 0;
  int answer= 0;
  int money;
  cin >> n;

  for (int i =0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    max_n = max(max_n,arr[i]);
  }
  cin >> money;
  if (sum <= money){
    cout << max_n;
    return 0;
  }


  while (min_n <= max_n) {
    int mid = (min_n + max_n) / 2;

    int ssum = (getSum(arr,n,mid));


    if (ssum > money) {
        max_n = mid -1;
    } else {
        answer = max(answer,mid);
        min_n = mid +1;
    }
  }
  cout << answer;

  return 0;
}
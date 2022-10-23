#include <string>
#include <vector>

using namespace std;

int delZero(string& next_s){
    int cnt_zero=0;
    for(int i=0;i<next_s.size();i++){
        if(next_s[i]=='0')cnt_zero++;
    }
    return cnt_zero;
}

string dec2bin(int num){
    string num_bin = "";
    while(num>0){
        int div = num/2;
        int mod = num%2;
        num = div;
        num_bin = to_string(mod) + num_bin;
    }
    return num_bin;
}
vector<int> solution(string s) {
    vector<int> answer;

    int sum_zero = 0;
    int cnt_trans = 0;
    while(1){
        if(s == "1")break;
        int cnt_zero= delZero(s);
        s = dec2bin(s.size()-cnt_zero);
        sum_zero+=cnt_zero;
        cnt_trans++;
    }
    
    answer.push_back(cnt_trans);
    answer.push_back(sum_zero);
    
    return answer;
}
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> temp(3,0);
    
    int a[] = {1,2,3,4,5};
    int b[] = {2,1,2,3,2,4,2,5};
    int c[] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==a[i%5])
            temp[0]++;
        if(answers[i]==b[i%8])
            temp[1]++;
        if(answers[i]==c[i%10])
            temp[2]++;
    }
    
    int mmax = max(max(temp[0], temp[1]), temp[2]);

    for(int i=0; i<3; i++){
        if(temp[i]==mmax){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
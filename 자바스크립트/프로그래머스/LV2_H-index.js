function solution(citations) {
    let answer = 0;
    citations.sort((a,b)=>{return b-a;});
    
    for(let i=0 ; i<citations.length; ++i) {
        if(i+1<=citations[i]) {
            ++answer;
        }
    }
    return answer;
}
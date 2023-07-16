function solution(start, end) {
    var answer = [];
    
    for (let s = start; s >= end; s--)
        {
            answer.push(s);
        }
    return answer;
}
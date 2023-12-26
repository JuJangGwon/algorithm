function solution(sequence, k) {
    let [start,end] = [0,0]
    let sum_ = sequence[0]
    let answer = [0,sequence.length]
    
    while(start < sequence.length){
        if (sum_ < k && start < sequence.length){
            sum_ += sequence[++end]
        }  else if (sum_ === k && end-start < answer[1]-answer[0]){
            answer = [start,end]
            sum_ += sequence[++end]
        } else sum_ -= sequence[start++]
    }
    return answer
}
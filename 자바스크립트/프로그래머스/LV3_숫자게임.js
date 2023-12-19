function solution(A, B) {
    var answer = 0;
    let startA = 0;
    let startB = 0;
    
    A.sort((a,b)=>b-a);
    B.sort((a,b)=>b-a);
    
    while (startA < A.length)
    {
        if(A[startA] < B[startB])
        {
            answer++;
            startA++;
            startB++;
        } else {
             startA++;
        }
    }
    return answer;
}
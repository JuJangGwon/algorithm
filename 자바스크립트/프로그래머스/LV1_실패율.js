function solution(N, stages) {
    var answer = [];
    
    for (let i = 1; i <= N; i++)
    {
        let top = stages.filter((event)=> event ===i)
        let temp = stages.filter((event)=> event >=i)
        answer.push([i,(top.length/temp.length)]);
    }
    answer = answer.sort((a,b) => b[1] - a[1])
    return answer.map((a)=>a[0]);
}
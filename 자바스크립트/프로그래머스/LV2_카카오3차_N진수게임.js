function solution(n, t, m, p) {
    var answer = [];
    let index = 0;
    const arr = [];
    
    while(arr.length <= t*m)
    {
       arr.push(...(index++).toString(n).toUpperCase().split(''))
    }
    for (let i = 0; i < t; i++)
    {
        answer.push(arr[i*m+(p-1)])
    }
    return answer.join('');
}
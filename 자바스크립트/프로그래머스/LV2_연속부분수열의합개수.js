function solution(elements) {
    let answer = new Set();
    const ary = [...elements,...elements];
    
    for (let i = 0; i <elements.length; i++)
    {
        for (let j = 0 ; j < elements.length; j++)
        {
            let sum = 0;
            for (let k = 0; k <= i; k++)
            {
                sum += ary[j+k];
            }
            answer.add(sum);
        }
    }
    return answer.size;
}
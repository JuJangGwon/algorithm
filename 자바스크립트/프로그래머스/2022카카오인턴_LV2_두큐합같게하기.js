function solution(queue1, queue2) {
    
    let sum1 = queue1.reduce((pre,cur)=>pre+cur,0);
    let sum2 = queue2.reduce((pre,cur)=>pre+cur,0);
    let start = 0;
    let end = queue1.length;
    const arr = [...queue1,...queue2];
    let count = 0;
    const length = queue1.length;
    const middle = (sum1+sum2)/2;
    for (let i = 0; i < length*3; i++)
    {
        if (sum1 === middle)
        {
            return count;
        }
        else if (sum1 > middle)
        {
            sum1-= arr[start++] 
        }
        else {
            sum1+= arr[end++] 
        }
        count++;
    }
    return -1;
}
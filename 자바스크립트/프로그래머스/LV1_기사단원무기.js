function solution(number, limit, power) {
    let answer = 0;
    let arr=Array(number);
    let i=1;
    
    while(i<=number)
    {
        let cnt=0
        for(let j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                cnt++
                if (j*j < i) 
                    cnt++
            }
        }
        arr[i-1]=cnt
        i++
    }
    arr.forEach(event=>{
        if(event>limit)
            answer+=power
    })
    answer+=arr.filter(event=> event<=limit).reduce((a,b)=>a+b,0)
    return answer
}
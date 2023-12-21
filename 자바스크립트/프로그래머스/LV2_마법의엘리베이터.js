function solution(storey) {
    var answer = 0;
    
    let arr = storey.toString().split('').reverse();
    arr = [...arr,0];
    console.log(arr);
    for (let c in arr)
    {
        c = Number(c);
        if (arr[c] < 5)
        {
            answer+=Number(arr[c]);
        } else if(arr[c] === 5 || arr[c] === '5'){
            if (arr[c+ 1] > 4)
            {
                answer +=Number(arr[c]);
                arr[c+1]= Number(arr[c+1]) + 1
            } else {
                 answer+=Number(arr[c]);
            }
        } else  {
            answer += 10 - Number(arr[c])
            arr[c+1]= Number(arr[c+1]) + 1
        }
    }
    return answer;
}
function solution(topping) {
    var answer = 0;
    const leftMap = new Map();
    
    const rightMap = new Map();
    for (let i =0 ; i<topping.length; i++)
    {
        if (!rightMap.get(topping[i]))  rightMap.set(topping[i],1);
        else rightMap.set(topping[i],rightMap.get(topping[i])+1);
    }
    for (let i = 0; i< topping.length; i++)
    {
        if (!leftMap.get(topping[i])) leftMap.set(topping[i],1);
        else leftMap.set(topping[i],leftMap.get(topping[i])+1);
        if(rightMap.get(topping[i]) === 1)  rightMap.delete(topping[i])
        else rightMap.set(topping[i],rightMap.get(topping[i])-1);
        if(leftMap.size === rightMap.size)  answer++;
    }
    
    
    return answer;
}
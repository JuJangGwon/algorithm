function solution(want, number, discount) {
    var answer = 0;
    let map = new Map();
    
      for (let i = 0; i < want.length; i++)
    {
         if(map.get(want[i])===undefined)
            map.set(want[i],0);
    }
    for (let i = 0 ; i < 10; i++)
    {
        map.set(discount[i],map.get(discount[i])+1);
    }
    function checking()
    {
        for (let i = 0; i < number.length; i++)
        {
            if(map.get(want[i]) < number[i])
                return false;
        }
        return true;
    }
   
    for (let i = 0; i < discount.length-9; i++)
    {
        if (i !== 0)
        {
            map.set(discount[i-1],map.get(discount[i-1])-1);
            map.set(discount[i+9],map.get(discount[i+9])+1);
        }
        if(checking() === true)
            answer++;
    }
    
    return answer;
}
function solution(priorities, location) {
    var answer = 0;
    priorities = priorities.map((item,index)=> {
        return {item, index};
    })
    while (priorities.length)
    {
       if (priorities.every((item)=> item.item <= priorities[0].item))
        {
            const c = priorities.shift();
            answer+=1;
            if (c.index === location)
            {
                
                return answer;
            }
        }
        else {
            const c = priorities.shift();
            priorities.push(c);
        }
    }
    return answer;
}
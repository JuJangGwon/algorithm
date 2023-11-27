function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    let time = 1;
    let weight_sum = 0;
    let truck_pivot = 0;
    const queue = [];
    
    while(true)
    {
        if (queue.length && queue[0].time +bridge_length === time)
        {
            weight_sum -= queue[0].weight;
            const c =queue.shift();
            if(!queue.length && truck_pivot === truck_weights.length)
                return time;
        }
        if (weight_sum + truck_weights[truck_pivot] <= weight)
        {
            weight_sum+= truck_weights[truck_pivot];
            queue.push({time : time,weight : truck_weights[truck_pivot++]})
        }
        time+=1;
    }
    return answer;
}
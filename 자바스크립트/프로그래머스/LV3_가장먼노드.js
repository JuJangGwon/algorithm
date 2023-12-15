function solution(n, edge) {
    var answer = 0;
    const map = Array.from({length : n+1},()=>[]);
    let maxnum = 0;
    const visited = Array.from({length : n+1},()=> 9999999);
    visited[1]=0;
    visited[0]=0;

    edge.map((item)=>{
        map[item[0]].push(item[1]);
        map[item[1]].push(item[0]);
    })
    
    const queue = [{node : 1, num : 0}];
    
    while (queue.length)
    {
        const {node , num} = queue.shift();
        maxnum = Math.max(num,maxnum);
        for(let i of map[node])
        {
            if (visited[i] > num+1)
            {
                visited[i] = num+1;
                queue.push({node:i,num:num+1});
            }
        }
    }
    for (let i = 1; i <= n; i++)
    {
        if (visited[i] === maxnum)
        {
            answer++;
        }
    }
    return answer;
}
const xx = [1,-1,0,0];
const yy = [0,0,1,-1];


function solution(maps) {
    var answer = [];

    const x = maps[0].length;
    const y = maps.length;
    
    const visited = Array.from({ length: y }, () => Array(x).fill(0));
    function bfs(num)
    {
        let ans = 0;
        const queue = [num];
        while(queue.length)
        {
            const c = queue.shift();
            const x1 = c.x;
            const y1 = c.y;
          
            ans += Number(maps[y1][x1]);
            
            for(let i =0 ;i < 4; i++)
            {
                const now_x = x1+xx[i];
                const now_y = y1+yy[i];
                
                if (now_x >= 0 && now_y >= 0 && now_x < x && now_y < y)
                {
                    if(visited[now_y][now_x] === 0 && maps[now_y][now_x] !== "X")
                    {
                        visited[now_y][now_x] = 1;
                        queue.push({x:now_x, y : now_y});
                    }
                }
            }
        }
        return ans;
    }
    
    for (let i = 0; i < y; i++)
    {
        for (let j =0; j < x; j++)
        {
            if(visited[i][j] === 0 &&  maps[i][j] !== "X")
            {
                visited[i][j] = 1;
                answer.push( bfs({x:j,y:i}));
            }
        }
    }
    
    return answer.length ? answer.sort() : [-1];
}
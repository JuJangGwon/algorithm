const dirX = [0,0,1,-1];
const dirY = [1,-1,0,0];

function solution(maps) {
    
    let x_length = maps[0].length;
    let y_length = maps.length;
    let startX;
    let startY;
    let score = 0;
    const arr = Array.from({length : y_length+1},()=>Array.from({length : x_length+1},()=>false));
    for (let i = 0; i < y_length; i++)
    {
        for (let j =0; j < x_length; j++)
        {
            if(maps[i][j] === 'S')
            {
                startY = i;
                startX = j;
            }
                
        }
    }
    const queue = [{x :startX, y:startY,num : 0}];
    arr[startY][startX] = true;
    while(queue.length)
    {
        const c = queue.pop();
        const x = c.x;
        const y = c.y;
        const num = c.num;
        if (maps[y][x] === 'L')
        {
            startX = x;
            startY = y;
            score = num;
            break;
        }
        for (let i = 0; i <4; i++)
        {
            const new_x = x+dirX[i];
            const new_y = y+dirY[i];
            if (new_x >= 0 && new_y >= 0 && new_x < x_length && new_y < y_length )
            {
                if ((!arr[new_y][new_x])&& maps[new_y][new_x] !=='X')
                {
                    arr[new_y][new_x] = true;
                    queue.push({x : new_x, y : new_y, num : num+1});
                }
            }
        }
    
    }
    const queue2 = [{x :startX, y:startY,num : 0}];
    for (let i = 0; i < y_length; i++)
    {
        for (let j =0; j < x_length; j++)
        {
            arr[i][j] =false;
        }
    }
    arr[startY][startX] = true;
    
    while(queue2.length)
    {
        const c = queue2.pop();
        const x = c.x;
        const y = c.y;
        const num = c.num;
        if (maps[y][x] === 'E')
        {
            return (score + num);
        }
        for (let i = 0; i <4; i++)
        {
            const new_x = x+dirX[i];
            const new_y = y+dirY[i];
            if (new_x >= 0 && new_y >= 0 && new_x < x_length && new_y < y_length )
            {
                if ((!arr[new_y][new_x])&& maps[new_y][new_x] !=='X')
                {
                    arr[new_y][new_x] = true;
                    queue2.push({x : new_x, y : new_y, num : num+1});
                }
            }
        }
    
    }
    return -1;
}
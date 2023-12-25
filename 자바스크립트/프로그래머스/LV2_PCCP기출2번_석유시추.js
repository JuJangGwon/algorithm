const dx = [0,0,-1,1];
const dy = [1,-1,0,0];

function solution(land) {
    var answer = 0;
    const Xlength = land[0].length;
    const Ylength = land.length;
    
    const answers = Array.from({length : Xlength},()=>0);
    const visited = Array.from({length : land.length+1},()=>Array.from({length : land [0].length+1},()=>false));
    
    function bfs(x1,y1)
    {
        let mine = 0;
        const arr = [{x:x1,y:y1}];
        const set = new Set();
        visited[y1][x1] = true;
        
        while (arr.length)
        {
            mine+=1;
            const pops = arr.pop();
            const {x,y} = pops;
            set.add(x);
            for (let i = 0; i < 4; i++)
            {
                const nextX = x + dx[i];
                const nextY = y + dy[i];
                
                if (nextX  >= 0 && nextY >= 0 && nextX < Xlength && nextY < Ylength && visited[nextY][nextX] === false && land[nextY][nextX] === 1)
                {
                    arr.push({x : nextX,y : nextY});
                    visited[nextY][nextX] = true;
                }
            }
        }
        set.forEach((item)=>{
            answers[item] += mine; 
        })
    }
    for (let i = 0; i< Ylength; i++)
    {
        for (let j = 0; j < Xlength; j++)
        {
          if(land[i][j] === 1 && !visited[i][j])   
           {
              bfs(j,i)
           }
        }
    }
    return  Math.max(...answers);;
}
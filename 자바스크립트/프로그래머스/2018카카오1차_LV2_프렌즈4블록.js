function solution(m, n, board) {
    var answer = 0;
    let is_change = true;
    const visited = Array.from({length:m+2},()=>Array.from({length : n+2},()=>false))
    for(let i = 0; i < m; i++)
    {
        board[i] = board[i].split('');
    }
    while (is_change)
    {        
        is_change = false;
        for(let i = 0; i< m-1; i++)
        {
            for (let j = 0; j < n-1;j++)
            {
                const char = board[i][j];
                if (char === " ")
                    continue ;
                if (board[i][j+1] === char && board[i+1][j+1] === char && board[i+1][j] === char)
                {
                    is_change=true;
                    visited[i][j] = true;                          
                    visited[i+1][j] = true;                          
                    visited[i+1][j+1] = true;                          
                    visited[i][j+1] = true;    
                }
           }
         }
        
        if (is_change)
        {
            for (let i = 0; i < m; i++)
            {
                for (let j = 0; j < n; j++)
                {
                    if (visited[i][j])
                    {
                        visited[i][j] = false;
                        board[i][j] = " ";
                        answer++;
                    }         
                }
            }
            
             for (let i = 0; i < n; i++)
            {
                const arr = [];
                for (let j = 0; j < m; j++)
                {
                    if(board[j][i] !== " ") 
                         arr.push(board[j][i]);
                    board[j][i] = " ";
                }
                for (let j = 0; j < arr.length ; j++)
                {
                    board[m-j-1][i] = arr[arr.length-j-1];
                }
            }            
        }
        
    }
    
    return answer;
}
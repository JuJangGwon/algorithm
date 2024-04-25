function solution(rows, columns, queries) {
  const answer = [];
  const dx = [1,0,-1,0];
  const dy = [0,1,0,-1];
  
  let i = 1;
  const board = Array.from({length : rows},()=> Array.from({length : columns}, ()=> i++));
  
  queries.map((query,index)=> {
      const start1 = { x : query[1]-1, y : query[0]-1};
      const start2 = { x : query[3]-1, y : query[2]-1};
      let nowPos = { x : query[1]-1, y : query[0]-1};
      let piror = board[start1.y][start1.x];
      let mins = 99999999;
      for (let i = 0; i < 4; i ++) {
          while(nowPos.x + dx[i] >= start1.x && nowPos.y + dy[i] >= start1.y && nowPos.x + dx[i] <= start2.x && nowPos.y + dy[i] <= start2.y ){
              
              nowPos.x += dx[i];
              nowPos.y += dy[i];
              const temp = board[nowPos.y][nowPos.x];
              board[nowPos.y][nowPos.x] = piror;
              mins = Math.min(mins, board[nowPos.y][nowPos.x]);
              piror = temp;
          }
      }
    answer.push(mins);
      
  })
  return answer;
}
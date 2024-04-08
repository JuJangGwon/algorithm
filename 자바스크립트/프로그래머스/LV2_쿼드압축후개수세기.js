function solution(arr) {
    
  function checker(len, x, y) {
        let zero = 0;
        let one = 0;
        for (let i = y; i<y+len; i++) {
              for (let j = x; j < x+len; j++) {
                  if (arr[i][j]===1) {
                      one++;
                  }
                  else {
                      zero++;
                  }
                  if (one > 0 && zero >0) {
                      return -1;
                  }
              }
          }
      if (zero){
          return 0;
      }
      return 1;
  }
  
  function dfs(len, x,y) {
      
      if (len === 1) {
          if (arr[y][x]) {
              return [0,1]
          } else {
              return [1,0]
          }
      } else {
       switch(checker(len,x,y)) {
           case -1:
            const leftup =  dfs(len/2,x,y);
            const rightup = dfs(len/2,x+len/2,y);
            const leftdown = dfs(len/2,x+len/2,y+len/2);
            const rightdown = dfs(len/2,x,y+len/2);
            return [leftup[0] + rightup[0] + leftdown[0] + rightdown[0], 
                    leftup[1] + rightup[1] + leftdown[1] + rightdown[1]]
               break;
           case 0:
               return [1,0];
               break;
           case 1:
               return [0,1];
               break;
       }
      }
  }
  
  const answer = dfs(arr.length,0,0)
  return answer;
}
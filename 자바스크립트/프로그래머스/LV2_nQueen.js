function solution(n) {
  const board = new Array(n).fill(-1)
  let answer = 0
  
  const isValid = (board,col,row) => {
      for (let i = 0 ; i < col ; i++) {
          if (board[i]===row) return false
          if (Math.abs(col-i) === Math.abs(row - board[i])) return false
      }
      return true
  }
  
  const dfs = (col,board) => {
      const tmpBoard = [...board]
      if (col === n) answer ++
      
      for (let row = 0 ; row < n ; row++){
          if (isValid(tmpBoard,col,row)) {
              tmpBoard[col] = row
              dfs(col+1,[...tmpBoard])
          }
      }
  }
  dfs(0,board)
  return answer
}

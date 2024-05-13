function solution(board, moves) {
  var answer = 0;

  const stack = [];
  console.log(board);
  moves.forEach((item) => {
    let height = 0;
    while (height < board.length && !board[height][item - 1]) {
      height += 1;
    }
    if (height < board.length) {
      const doll = board[height][item - 1];
      board[height][item - 1] = 0;

      if (stack.length && stack[stack.length - 1] === doll) {
        answer += 2;
        stack.pop();
      } else {
        stack.push(doll);
      }
    }
  });
  return answer;
}

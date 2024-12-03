function solution(board, skill) {
  const dp = Array.from({ length: board.length + 1 }, () =>
    Array.from({ length: board[0].length + 1 }, () => 0)
  );
  const arr = Array.from({ length: board.length + 1 }, () =>
    Array.from({ length: board[0].length + 1 }, () => 0)
  );
  skill.forEach((item) => {
    const num = item[0] === 1 ? -item[5] : item[5];
    const [_, y1, x1, y2, x2] = item;
    arr[y1][x1] += num;
    arr[y1][x2 + 1] -= num;
    arr[y2 + 1][x1] -= num;
    arr[y2 + 1][x2 + 1] += num;
  });
  for (let i = 0; i < board.length + 1; i++) {
    for (let j = 0; j < board[0].length + 1; j++) {
      dp[i][j] =
        (i === 0 ? 0 : dp[i - 1][j]) +
        (j === 0 ? 0 : dp[i][j - 1]) +
        arr[i][j] -
        (i != 0 && j != 0 ? dp[i - 1][j - 1] : 0);
    }
  }
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      board[i][j] += dp[i][j];
    }
  }
  let answer = 0;
  board.forEach((item) => {
    answer += item.filter((item2) => item2 >= 1).length;
  });
  return answer;
}

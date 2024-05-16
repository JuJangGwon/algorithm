const dir = [
  { dir: "left", pos: [-1, 0] },
  { dir: "right", pos: [1, 0] },
  { dir: "up", pos: [0, 1] },
  { dir: "down", pos: [0, -1] },
];

function solution(board) {
  var answer = 0;

  const q = [{ pos: [0, 0], price: 0, dir: "" }];
  const visited = Array.from({ length: board.length }, () =>
    Array.from({ length: board.length }, () =>
      Array.from({ length: 4 }, () => 999999)
    )
  );
  visited[0][0] = 0;
  while (q.length) {
    const s = q.shift();
    const pos = s.pos;
    const price = s.price;
    const nowdir = s.dir;
    for (let i = 0; i < 4; i++) {
      const nextPos = [pos[0] + dir[i].pos[0], pos[1] + dir[i].pos[1]];
      const nextDir = dir[i].dir;
      let nextPrice = price + 100;
      if (!(nowdir === "" || nextDir === nowdir)) {
        nextPrice += 500;
      }
      if (
        nextPos[0] >= 0 &&
        nextPos[1] >= 0 &&
        nextPos[0] < board[0].length &&
        nextPos[1] < board.length &&
        board[nextPos[1]][nextPos[0]] === 0
      ) {
        if (visited[nextPos[1]][nextPos[0]][i] > nextPrice) {
          visited[nextPos[1]][nextPos[0]][i] = nextPrice;
          q.push({
            pos: [nextPos[0], nextPos[1]],
            dir: nextDir,
            price: nextPrice,
          });
        }
      }
    }
  }
  return Math.min(...visited[board.length - 1][board[0].length - 1]);
}

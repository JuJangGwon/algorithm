const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = parseInt(input[0]);
  const map = [];
  for (let i = 1; i <= N; i++) {
    map.push(input[i].split(" ").map(Number));
  }

  let ans = -1;
  const isVisited = Array.from({ length: N }, () => Array(N).fill(false));
  const dirX = [0, 1];
  const dirY = [1, 0];

  const solve = () => {
    const maxDepth = N === 2 ? 2 : 4;

    const DFS = (depth, sum) => {
      if (depth === maxDepth) {
        ans = Math.max(ans, sum);
        return;
      }

      for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
          if (isVisited[i][j]) continue;

          for (let k = 0; k < 2; k++) {
            const nextX = dirX[k] + i;
            const nextY = dirY[k] + j;

            if (!isAble(nextX, nextY)) continue;

            isVisited[i][j] = true;
            isVisited[nextX][nextY] = true;
            DFS(depth + 1, sum + map[i][j] + map[nextX][nextY]);
            isVisited[i][j] = false;
            isVisited[nextX][nextY] = false;
          }
        }
      }
    };

    const isAble = (nextX, nextY) => {
      return (
        nextX >= 0 &&
        nextX < N &&
        nextY >= 0 &&
        nextY < N &&
        !isVisited[nextX][nextY]
      );
    };

    DFS(0, 0);
    return ans;
  };

  console.log(solve());
});

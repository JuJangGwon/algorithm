const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
const dx = [1, -1, 0, 0];
const dy = [0, 0, -1, 1];

rl.on("line", (line) => {
  input.push(line.split(" ").map(Number));
}).on("close", () => {
  const [n, m] = input[0];
  const map = input.slice(1, 1 + n);
  const visited = Array.from({ length: n + 1 }, () =>
    Array.from({ length: n + 1 }, () => 0)
  );
  input
    .slice(1 + n)
    .forEach((item, index) => (visited[item[0]][item[1]] = index + 1));
  let answer = 0;
  const dfs = (x, y, k) => {
    if (k === m + 1) {
      answer += 1;
      return;
    }
    for (let i = 0; i < 4; i++) {
      let nowX = x + dx[i];
      let nowY = y + dy[i];
      if (nowX >= 1 && nowY >= 1 && nowX <= n && nowY <= n) {
        if (
          (map[nowY - 1][nowX - 1] === 0 && visited[nowY][nowX] === 0) ||
          visited[nowY][nowX] === k
        ) {
          const temp = visited[nowY][nowX];
          const newK = temp === 0 ? k : k + 1;
          visited[nowY][nowX] = -1;
          dfs(nowX, nowY, !temp ? k : k + 1, newK);
          visited[nowY][nowX] = temp;
        }
      }
    }
  };
  visited[input[1 + n][0]][input[1 + n][1]] = -1;
  dfs(input[1 + n][1], input[1 + n][0], 2);
  console.log(answer);

  process.exit(0);
});

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const inputData = [];

rl.on("line", (line) => {
  inputData.push(line.split(" ").map((e) => Number(e)));
}).on("close", () => {
  const [n, m] = inputData[0];
  const nAdjL = Array.from({ length: n + 1 }, () => []);
  const rAdjL = Array.from({ length: n + 1 }, () => []);
  for (let i = 1; i <= m; i++) {
    const [st, to] = inputData[i];
    nAdjL[st].push(to);
    rAdjL[to].push(st);
  }
  const [s, t] = inputData[m + 1];
  const dfs = (start, visited, adjL) => {
    const stack = [start];
    visited[start] = 1; // 시작 노드 방문 표시
    while (stack.length > 0) {
      const node = stack.pop();
      for (const nextNode of adjL[node]) {
        if (!visited[nextNode]) {
          visited[nextNode] = 1; // 방문 표시
          stack.push(nextNode);
        }
      }
    }
  };

  const fromS = Array(n + 1).fill(0);
  const fromT = Array(n + 1).fill(0);
  const toS = Array(n + 1).fill(0);
  const toT = Array(n + 1).fill(0);

  fromS[t] = 1;
  dfs(s, fromS, nAdjL);
  fromT[s] = 1;
  dfs(t, fromT, nAdjL);
  dfs(s, toS, rAdjL);
  dfs(t, toT, rAdjL);
  let cnt = 0;
  for (let i = 1; i <= n; i++) {
    if (fromS[i] && fromT[i] && toS[i] && toT[i]) {
      cnt += 1;
    }
  }
  console.log(cnt - 2);
  process.exit(0);
});

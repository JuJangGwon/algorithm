const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];

rl.on("line", (line) => {
  input.push(line.split(" "));
}).on("close", () => {
  const [n, m] = [parseInt(input[0][0]), parseInt(input[0][1])];
  const ghost = [];
  let myPos;
  let arrivePoint;
  const map = input.slice(1).map((xList, y) => {
    return xList[0].split("");
  });
  map.forEach((xList, y) => {
    xList.forEach((item, x) => {
      if (item === "D") {
        arrivePoint = { x: x, y: y };
      } else if (item === "G") {
        ghost.push({ x: x, y: y });
      } else if (item === "N") {
        myPos = { x: x, y: y };
      }
    });
  });
  const bfs = (xx, yy, ghost) => {
    const visited = Array.from({ length: n + 1 }, () =>
      Array.from({ length: m + 1 }, () => false)
    );
    const queue = [{ x: xx, y: yy, cost: 0 }];
    visited[yy][xx] = true;

    while (queue.length) {
      const now = queue.shift();
      const nowX = now.x;
      const nowY = now.y;
      const nowCost = now.cost;

      if (nowX === arrivePoint.x && nowY === arrivePoint.y) {
        return nowCost;
      }

      for (let i = 0; i < 4; i++) {
        const nextX = nowX + dx[i];
        const nextY = nowY + dy[i];
        if (
          nextX >= 0 &&
          nextX < m &&
          nextY >= 0 &&
          nextY < n &&
          !visited[nextY][nextX]
        ) {
          if (map[nextY][nextX] === "#" && ghost === false) continue;
          queue.push({ x: nextX, y: nextY, cost: nowCost + 1 });
          visited[nextY][nextX] = true;
        }
      }
    }
    return -1;
  };
  let num = bfs(myPos.x, myPos.y, false);
  if (num === -1) {
    console.log("No");
    return;
  }
  for (let i = 0; i < ghost.length; i++) {
    if (
      Math.abs(ghost[i].x - arrivePoint.x) +
        Math.abs(ghost[i].y - arrivePoint.y) <=
      num
    ) {
      console.log("No");
      return;
    }
  }
  console.log("Yes");
});

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];

let input = [];
rl.on("line", (line) => {
  input.push(line.split(" "));
}).on("close", () => {
  let score = 0;
  const [n, m] = input[0].map(Number);
  const friends = input.slice(n + 1).map((item) => {
    return [parseInt(item[0]) - 1, parseInt(item[1]) - 1];
  });
  const map = input.slice(1, 1 + n);
  let friendsPoint = [];
  const friendsNum = friends.length;
  const visited = Array.from({ length: m }, () =>
    Array.from({ length: n }, () => Array.from({ length: n }, () => false))
  );

  friends.forEach((item, index) => {
    visited[index][parseInt(item[0])][parseInt(item[1])] = true;
    friendsPoint[index] = parseInt(map[parseInt(item[0])][parseInt(item[1])]);
  });
  const dfs = (friendsStatus, friendsXY) => {
    if (friendsStatus.every((item) => item === 3)) {
      let tempScore = 0;
      friendsPoint.forEach((item) => {
        tempScore += item > 1000 ? 1000 : item;
      });
      score = Math.max(score, tempScore);
      return;
    }
    if (friendsStatus.every((item) => item === friendsStatus[0])) {
      for (let i = 0; i < 4; i++) {
        let nextX = dx[i] + friendsXY[0][1];
        let nextY = dy[i] + friendsXY[0][0];
        if (
          nextX >= 0 &&
          nextY >= 0 &&
          nextX < n &&
          nextY < n &&
          !visited[0][nextY][nextX]
        ) {
          const checker = () => {
            for (let u = 1; u < m; u++) {
              if (visited[u][nextY][nextX]) return false;
            }
            return true;
          };
          visited[0][nextY][nextX] = true;
          friendsStatus[0] += 1;
          friendsPoint[0] += checker() ? parseInt(map[nextY][nextX]) : 0;
          let tempfriendsXy = [...friendsXY];
          tempfriendsXy[0] = [nextY, nextX];
          dfs([...friendsStatus], tempfriendsXy);
          friendsStatus[0] -= 1;
          visited[0][nextY][nextX] = false;
          friendsPoint[0] -= checker() ? parseInt(map[nextY][nextX]) : 0;
        }
      }
    } else {
      for (let i = 1; i < friendsStatus.length; i++) {
        for (let j = friendsStatus[i]; j < 3; j++) {
          for (let o = 0; o < 4; o++) {
            let nextX = dx[o] + friendsXY[i][1];
            let nextY = dy[o] + friendsXY[i][0];

            if (
              nextX >= 0 &&
              nextY >= 0 &&
              nextX < n &&
              nextY < n &&
              !visited[i][nextY][nextX]
            ) {
              for (let v = 0; v < i; v++) {
                if (friendsXY[v][0] === nextY && friendsXY[v][1] === nextX)
                  break;
              }
              visited[i][nextY][nextX] = true;
              const checker = () => {
                for (let u = 0; u < m; u++) {
                  if (u === i) continue;
                  if (visited[u][nextY][nextX]) return false;
                }
                return true;
              };
              friendsStatus[i] += 1;
              friendsPoint[i] += checker() ? parseInt(map[nextY][nextX]) : 0;

              let tempfriendsXy = [...friendsXY];
              tempfriendsXy[i] = [nextY, nextX];
              dfs([...friendsStatus], tempfriendsXy);
              friendsStatus[i] -= 1;
              visited[i][nextY][nextX] = false;
              friendsPoint[i] -= checker() ? parseInt(map[nextY][nextX]) : 0;
            }
          }
        }
      }
    }
  };
  dfs(
    Array.from({ length: m }, () => 0),
    [...friends]
  );
  console.log(score);
});

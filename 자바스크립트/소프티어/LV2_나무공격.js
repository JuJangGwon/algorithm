const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let n, m;
rl.on("line", (line) => {
  input.push(line.split(" "));
}).on("close", () => {
  [n, m] = input[0];
  input = input.slice(1);
  const attack1 = input[input.length - 1];
  const attack2 = input[input.length - 2];
  input = input.slice(0, n);

  for (let i = attack1[0] - 1; i <= attack1[1] - 1; i++) {
    for (let j = 0; j < m; j++) {
      if (input[i][j] === "1") {
        input[i][j] = "0";
        break;
      }
    }
  }

  for (let i = attack2[0] - 1; i <= attack2[1] - 1; i++) {
    for (let j = 0; j < m; j++) {
      if (input[i][j] === "1") {
        input[i][j] = "0";
        break;
      }
    }
  }
  let answer = 0;
  input.forEach((item) => {
    item.forEach((item2) => {
      if (item2 === "1") answer += 1;
    });
  });
  console.log(answer);
  process.exit(0);
});

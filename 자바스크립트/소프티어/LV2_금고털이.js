const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdput,
});

let lines = [];

rl.on("line", (line) => {
  lines.push(line.split(" ").map(Number));
}).on("close", () => {
  let limit = lines[0];
  let answer = 0;
  lines = lines.slice(1).sort((a, b) => b[1] - a[1]);

  let pivot = 0;
  while (limit[0] > 0 && pivot < limit[1]) {
    if (lines[pivot][0] < limit[0]) {
      limit[0] -= lines[pivot][0];
      answer += lines[pivot][1] * lines[pivot][0];
    } else {
      answer += limit[0] * lines[pivot][1];
      limit[0] = 0;
    }
    pivot += 1;
  }
  console.log(answer);
  process.exit();
});

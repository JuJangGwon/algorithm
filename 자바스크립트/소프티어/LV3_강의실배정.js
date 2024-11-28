const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line.split(" ").map(Number));
}).on("close", () => {
  let arr = input.slice(1).sort((a, b) => a[1] - b[1]);
  let answer = 0;
  let pivot = 0;
  for (let i = 0; i < arr.length; i++) {
    if (pivot <= arr[i][0]) {
      answer += 1;
      pivot = arr[i][1];
    }
  }
  console.log(answer);
  process.exit(0);
});

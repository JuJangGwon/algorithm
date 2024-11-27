const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(...line.split(" ").map(Number));
}).on("close", () => {
  if (input[0] > input[1]) console.log("A");
  else if (input[0] < input[1]) console.log("B");
  else console.log("same");
  process.exit(0);
});

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let sum = 0;

rl.on("line", (input) => {
  let [timeA, timeB] = input.split(" ").map((el) => el.split(":"));
  sum += +timeB[0] * 60 + +timeB[1] - (+timeA[0] * 60 + +timeA[1]);
});

rl.on("close", () => {
  console.log(sum);
});

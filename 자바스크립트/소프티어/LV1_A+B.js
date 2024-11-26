const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let time = 0;
let input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  time = input[0];
  input = input.slice(1);
  input.forEach((item, index) => {
    const numbers = item.split(" ");
    console.log(
      `Case #${index + 1}: ${parseInt(numbers[0]) + parseInt(numbers[1])}`
    );
  });
  process.exit(0);
});

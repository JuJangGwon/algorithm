const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdput,
});

let lines = [];

rl.on("line", (line) => {
  lines.push(line.split(" ").map(BigInt));
}).on("close", () => {
  let answer = lines[0][0];

  let mod = BigInt(1000000007);
  for (let i = 0; i < lines[0][2]; i++) {
    answer = (answer * lines[0][1]) % mod;
  }
  console.log(parseInt(answer));
  process.exit();
});

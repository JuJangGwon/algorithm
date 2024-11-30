const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
const MOD = 1000000007n;

rl.on("line", (line) => {
  input.push(line.split(" ").map(BigInt));
}).on("close", () => {
  const Dived = (num) => {
    if (num === 1n) {
      return input[0][1];
    } else if (num % 2n === 0n) {
      let a = Dived(num / 2n);
      return (a * a) % MOD;
    } else {
      let a = Dived(num / 2n);
      return a * a * input[0][1];
    }
  };
  console.log(parseInt((Dived(input[0][2] * 10n) * input[0][0]) % MOD));
  process.exit(0);
});

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line.split(" ").map(Number));
}).on("close", () => {
  const [n, q] = input[0];
  const list = input[1].sort((a, b) => a - b);

  input.slice(2).forEach((query) => {
    const target = query[0];
    let left = 0;
    let right = list.length - 1;
    let found = false;

    while (left <= right) {
      const mid = Math.floor((left + right) / 2);

      if (list[mid] === target) {
        found = true;
        const leftCount = mid;
        const rightCount = list.length - 1 - mid;
        console.log(leftCount * rightCount);
        break;
      } else if (list[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (!found) {
      console.log(0);
    }
  });

  process.exit(0);
});

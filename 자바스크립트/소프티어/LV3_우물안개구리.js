const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line.split(" ").map(Number));
}).on("close", () => {
  const arr = Array.from(input[1]);
  const yes = Array.from({ length: input[0][0] + 1 }, () => true);
  const map = Array.from({ length: input[0][0] + 1 }, () => []);
  input.slice(2).forEach((item) => {
    map[item[0]].push(item[1]);
    map[item[1]].push(item[0]);
  });
  map.forEach((item, index) => {
    if (item.length === 0) {
      yes[index] = true;
    } else {
      let temp = 0;
      for (let i = 0; i < item.length; i++) {
        if (arr[item[i] - 1] > arr[index - 1]) {
          yes[index] = false;
          break;
        }
        temp = Math.max(temp, arr[item[i] - 1]);
      }
      if (temp === arr[index - 1]) {
        yes[index] = false;
      }
    }
  });
  console.log(yes.filter((item) => item === true).length - 1);
  process.exit(0);
});

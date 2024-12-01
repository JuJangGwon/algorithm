const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line.split(" "));
}).on("close", () => {
  const visited = Array.from({ length: parseInt(input[0][0]) }, () => false);
  const num = parseInt(input[0][1]);
  let answer = 0;
  let aot = input[1][0].split("");
  aot.forEach((item, index) => {
    if (!visited[index]) {
      if (item === "H") {
        for (let i = index + 1; i <= index + num; i++) {
          if (aot[i] === "P" && !visited[i]) {
            answer += 1;
            visited[i] = true;
            visited[index] = true;
            break;
          }
        }
      } else {
        for (let i = index + 1; i <= index + num; i++) {
          if (aot[i] === "H" && !visited[i]) {
            answer += 1;
            visited[i] = true;
            visited[index] = true;
            break;
          }
        }
      }
    }
  });
  console.log(answer);
  process.exit(0);
});

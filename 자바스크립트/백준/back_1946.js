const solution = (list) => {
  list = list.map((item) => item.split(" ").map(Number));
  list = list.sort((a, b) => {
    return a[0] - b[0];
  });
  let least = list[0][1];
  let answer = 1;
  for (let i = 1; i < list.length; i++) {
    if (list[i][1] < least) {
      answer += 1;
      least = list[i][1];
    }
  }
  console.log(answer);
};

let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let testCase = input[0];
let inputPivot = 1;

for (let i = 0; i < testCase; i++) {
  const inputListLength = parseInt(input[inputPivot]);
  solution(input.slice(inputPivot + 1, inputPivot + 1 + inputListLength));
  inputPivot += inputListLength + 1;
}

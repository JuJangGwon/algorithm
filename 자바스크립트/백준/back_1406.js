// L 커서 왼쪽하나 옮김 , 맨앞 무시
// D 커서 오른쪽 한칸, 맨 뒤 무시
// B 커서 왼쪽에있는 문자 삭제, 맨 앞 무시,
// P 커서 왼쪽에 추가
// 커서는 맨뒤에서 시작

// 60만회.
// 0.3 초제한 - 3300만회 안에 연산을 끝내야함.

const solution = (editor, list) => {
  let leftStack = editor.split("");
  let rightStack = [];

  list.forEach(([cmd, char]) => {
    switch (cmd) {
      case "L":
        if (leftStack.length) rightStack.push(leftStack.pop());
        break;
      case "D":
        if (rightStack.length) leftStack.push(rightStack.pop());
        break;
      case "B":
        if (leftStack.length) leftStack.pop();
        break;
      case "P":
        leftStack.push(char);
        break;
    }
  });

  console.log(leftStack.join("") + rightStack.reverse().join(""));
};

let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let editor = input[0];
let list = input.slice(2).map((keyword) => keyword.split(" "));

solution(editor, list);

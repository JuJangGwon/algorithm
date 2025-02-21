let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const lineNum = input[0]
input = input.slice(1).map((item)=>item.split(""))

let max_num = 0;

const numChecker = (y,x) =>{
    let countY = 0;
    let countX = 0;
    for (let i = y-1; i >=0; i--){
        if (input[y][x] === input[i][x]){
            countY +=1
        } else {
            break;
        }
    }
   for (let i = y+1; i < lineNum; i++){
        if (input[y][x] === input[i][x]){
            countY +=1
        } else {
            break;
        }
    }
    // 
      for (let i = x-1; i >=0; i--){
        if (input[y][x] === input[y][i]){
            countX +=1
        } else {
            break;
        }
    }
   for (let i = x+1; i < lineNum; i++){
        if (input[y][x] === input[y][i]){
            countX +=1
        } else {
            break;
        }
    }
    return Math.max(countY+1,countX+1)
}

const swap1 = (i,j) =>{
   const temp = input[i][j]
    input[i][j] = input[i][j+1] 
    input[i][j+1] = temp
}

const swap2 = (i,j) =>{
   const temp = input[i][j]
    input[i][j] = input[i+1][j] 
    input[i+1][j] = temp
}

for (let i = 0; i < lineNum; i++){
    for (let j = 0; j < lineNum; j++){
      max_num = Math.max(numChecker(i,j),max_num)
    }
}

for (let i = 0; i < lineNum; i++){
    for (let j = 0; j < lineNum-1; j++){
      swap1(i,j)
      max_num = Math.max(numChecker(i,j),max_num)
      max_num = Math.max(numChecker(i,j+1),max_num)
      swap1(i,j)
        if (i < lineNum -1) {
      swap2(i,j)
      max_num = Math.max(numChecker(i,j),max_num)
      max_num = Math.max(numChecker(i+1,j),max_num)
      swap2(i,j)
        }
    }
}
console.log(max_num)
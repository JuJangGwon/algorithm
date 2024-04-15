function solution(expression) {
    
  let answer = null;
  const temp = expression.split(/(\-|\*|\+)/);
  const visited = [false,false,false];
  const operator = ["+","-","*"];
  
  function caculator(tempArr, tempOpereator) {
      let newArr = [tempArr[0]];
      for (let i = 1; i < tempArr.length; i+=2) {
          if (tempArr[i] === tempOpereator) {
              if (tempOpereator === "+") {
                  newArr[newArr.length-1] =  parseInt(newArr[newArr.length-1]) + parseInt(tempArr[i+1]);
              } else if (tempOpereator === "-"){
                   newArr[newArr.length-1] = parseInt(newArr[newArr.length-1]) - parseInt(tempArr[i+1]);
              } else {
                   newArr[newArr.length-1] = parseInt(newArr[newArr.length-1]) * parseInt(tempArr[i+1]);
              }
          } else {
              newArr = [...newArr,tempArr[i],tempArr[i+1]]
          }
      }
      return newArr;
  }
  
  const dfs = (arr, num) => {
      if (num === 3) {
          if (!answer) answer = arr[0];
          answer = Math.max(Math.abs(arr[0]) ,Math.abs(answer))
          return ;
      } else {
          for (let i = 0; i < 3; i++) {
              if (!visited[i]) {
                  visited[i] = true;
                  const nextArr = caculator(arr,operator[i])
                  dfs(nextArr,num+1);
                  visited[i] = false;
              }
          }
      }
  }
  
  dfs(temp,0)
  return answer;
}
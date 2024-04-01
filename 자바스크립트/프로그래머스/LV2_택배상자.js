function solution(order) {
  let answer = 0;
  let stack = [];
  let orderNum = 0;
  let boxNum = 1;
  for(let i=0; i<=order.length; i++){
      if(order[orderNum] === boxNum){
          answer++;
          orderNum++;
          boxNum++;
      }else if(stack.length && stack[stack.length-1] === order[orderNum]){
          answer++;
          orderNum++;
          stack.pop();
          i--; 
      }else{
          stack.push(boxNum);
          boxNum++;
      }
  }
  return answer;
}
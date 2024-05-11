function solution(ingredient) {
  var answer = 0;
  var stack = [];

  ingredient.forEach(ing => {
      stack.push(ing);
      if (stack.length >= 4) {
          const length = stack.length;
          if (stack[length - 4] === 1 && stack[length - 3] === 2 && stack[length - 2] === 3 && stack[length - 1] === 1) {
              stack.pop();
              stack.pop();
              stack.pop();
              stack.pop(); 
              answer++;
          }
      }
  });

  return answer;
}
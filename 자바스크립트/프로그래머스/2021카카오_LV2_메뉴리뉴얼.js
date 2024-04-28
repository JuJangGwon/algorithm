function solution(orders, course) {
  var answer = [];
const combinations = new Map();

function combine(menu, start, depth, maxDepth, arr) {
  if (depth === maxDepth) {
      const combination = arr.sort().join('');
      combinations.set(combination, (combinations.get(combination) || 0) + 1);
      return;
  }
  for (let i = start; i < menu.length; i++) {
      arr.push(menu[i]);
      combine(menu, i + 1, depth + 1, maxDepth, arr);
      arr.pop();
  }
}

orders.forEach(order => {
  const menu = order.split('').sort();
  course.forEach(c => {
      combine(menu, 0, 0, c, []);
  });
});
let courseMap = new Map();
combinations.forEach((count, combination) => {
  if (count > 1) {
      const len = combination.length;
      if (!courseMap.has(len) || courseMap.get(len).count < count) {
          courseMap.set(len, { count: count, combos: [combination] });
      } else if (courseMap.get(len).count === count) {
          courseMap.get(len).combos.push(combination);
          
      }
  }
});
courseMap.forEach((value) => {
  answer = [...answer, ...value.combos];
});

return answer.sort();
}
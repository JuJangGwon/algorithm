function solution(keymap, targets) {
  var answer = [];
  let map = {};
  keymap.forEach((key) => {
    key.split("").forEach((item, index) => {
      if (map[item] == null) {
        map[item] = index + 1;
      } else if (map[item] > index) {
        map[item] = index + 1;
      }
    });
  });
  targets.forEach((item) => {
    let count = 0;
    if (item.split("").some((i) => map[i] == null)) {
      answer.push(-1);
    } else {
      item.split("").forEach((i) => {
        count += map[i];
      });
      answer.push(count);
    }
  });
  return answer;
}

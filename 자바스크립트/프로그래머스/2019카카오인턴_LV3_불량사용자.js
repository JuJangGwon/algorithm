function solution(user_id, banned_id) {
  var answer = 0;
  const usedUser = user_id.map((item) => ({ [item]: false }));
  const bannedList = new Map();
  const v = new Map();

  function CompareChecker(userId, bannedId, compareWord) {
    if (userId.length !== bannedId.length) return false;
    for (let i of compareWord) {
      if (userId[i] !== bannedId[i]) return false;
    }
    return true;
  }

  banned_id.forEach((item) => {
    if (!bannedList.get(item)) {
      const compareWord = item
        .split("")
        .map((k, index) => {
          if (k !== "*") return index;
        })
        .filter((k) => k !== undefined);

      user_id.forEach((userId) => {
        if (CompareChecker(userId, item, compareWord)) {
          bannedList.set(
            item,
            bannedList.get(item) ? [...bannedList.get(item), userId] : [userId]
          );
        }
      });
    }
  });
  function Combinantion(num, arr) {
    if (num === banned_id.length) {
      if (!v.get(arr.sort().join(""))) {
        answer++;
        v.set(arr.sort().join(""), "0");
      }
      return;
    }
    for (let i of bannedList.get(banned_id[num])) {
      if (!usedUser[i]) {
        usedUser[i] = true;
        Combinantion(num + 1, [...arr, i]);
        usedUser[i] = false;
      }
    }
  }
  Combinantion(0, []);
  return answer;
}

function solution(s) {
  var answer = [];
  let tempArr = {};

  let temp = "";
  for (let i = 1; i < s.length - 1; i++) {
    if (s[i] === "{") {
      temp = "";
    } else if (s[i] === "}") {
      if (!tempArr[temp]) {
        tempArr[temp] = 1;
      } else {
        tempArr[temp] += 1;
      }
      i += 1;
      temp = "";
    } else if (s[i] === ",") {
      if (!tempArr[temp]) {
        tempArr[temp] = 1;
      } else {
        tempArr[temp] += 1;
      }
      temp = "";
    } else {
      temp += s[i];
    }
  }
  return Object.entries(tempArr)
    .sort((a, b) => b[1] - a[1])
    .map((item) => {
      return parseInt(item[0]);
    });
}

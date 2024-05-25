function solution(today, terms, privacies) {
  var answer = [];
  let v = {};
  terms.forEach((item) => {
    item = item.split(" ");
    v[item[0]] = parseInt(item[1]);
  });
  privacies.forEach((item, index) => {
    const privacy = item.split(" ");
    let day = new Date(privacy[0]);
    day.setMonth(day.getMonth() + v[privacy[1]]);
    if (new Date(today).getTime() >= day.getTime()) {
      answer.push(index + 1);
    }
  });
  return answer;
}
